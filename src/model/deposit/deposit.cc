// Copyright 2024 Burr Etienne
#include "deposit.h"

#include <cmath>

s21::Transaction::Transaction(const std::tm& date, double amount,
                              TransactionRecurrence recurrence)
    : date(date), amount(amount), recurrence(recurrence) {}

void s21::DepositModel::AddTransactions(
    const std::vector<Transaction>& transactions) {
  transactions_.clear();
  transactions_ = transactions;
}

void s21::DepositModel::Calculate() {
  NullableValues();
  CalculateEndDate();
  CalculateDeposit();
}

void s21::DepositModel::NullableValues() {
  total_interest_ = 0;
  total_tax_ = 0;
  total_sum_ = 0;
  end_date_ = {};
}

void s21::DepositModel::CalculateDeposit() {
  tm current = start_date_;
  current.tm_mday += 1;
  mktime(&current);

  double initial_amount = amount_;
  while (mktime(&current) <= mktime(&end_date_)) {
    for (auto& transaction : transactions_) {
      tm tmp_date = transaction.date;
      mktime(&tmp_date);
      if (transaction.recurrence == TransactionRecurrence::MONTHLY &&
          current.tm_mday == tmp_date.tm_mday) {
        initial_amount += transaction.amount;
      } else if (transaction.recurrence == TransactionRecurrence::ONCE &&
                 current.tm_mday == tmp_date.tm_mday &&
                 current.tm_mon == tmp_date.tm_mon &&
                 current.tm_year == tmp_date.tm_year) {
        initial_amount += transaction.amount;
      }
    }

    double interest = 0;
    double tax = 0;

    if (recurrence_ == TransactionRecurrence::DAILY) {
      interest = (initial_amount * (interest_ / 100.0)) / 365.0;
    } else if (recurrence_ == TransactionRecurrence::MONTHLY &&
               current.tm_mday == start_date_.tm_mday) {
      interest = (initial_amount * (interest_ / 100.0)) / 12.0;
    } else if (recurrence_ == TransactionRecurrence::ONCE &&
               mktime(&current) == mktime(&end_date_)) {
      double sum =
          initial_amount * pow((1 + ((interest_ / 100.0) / 12.0)), (term_));
      interest = sum - initial_amount;
    }

    if (capitalization_) {
      initial_amount += interest;
    } else {
      tax = interest * (tax_ / 100.0);
      total_interest_ += (interest - tax);
      total_tax_ += tax;
    }

    current.tm_mday += 1;
    mktime(&current);
  }
  if (capitalization_) {
    double interest_tmp = (initial_amount - amount_);
    total_tax_ = interest_tmp * (tax_ / 100.0);
    total_interest_ = interest_tmp - total_tax_;
  }
  total_sum_ = initial_amount + total_interest_;
}

void s21::DepositModel::SetAmount(double amount) { amount_ = amount; }

void s21::DepositModel::SetTerm(int term) { term_ = term; }

void s21::DepositModel::SetStartDate(const std::tm& start_date) {
  start_date_ = start_date;
}

void s21::DepositModel::SetInterest(double interest) { interest_ = interest; }

void s21::DepositModel::SetTax(double tax) { tax_ = tax; }

void s21::DepositModel::SetRecurrence(TransactionRecurrence recurrence) {
  recurrence_ = recurrence;
}

void s21::DepositModel::SetCapitalization(bool capitalization) {
  capitalization_ = capitalization;
}

void s21::DepositModel::CalculateEndDate() {
  end_date_ = start_date_;
  end_date_.tm_mon += term_;
  mktime(&end_date_);
}
double s21::DepositModel::GetTotalInterest() { return total_interest_; }
double s21::DepositModel::GetTotalTax() { return total_tax_; }
double s21::DepositModel::GetTotalSum() { return total_sum_; }
