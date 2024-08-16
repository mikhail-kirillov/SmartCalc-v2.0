// Copyright 2024 Burr Etienne
#include "deposit.h"

#include <vector>

void s21::DepositController::SetAmount(double amount) {
  model_.SetAmount(amount);
}

void s21::DepositController::SetTerm(int term) { model_.SetTerm(term); }

void s21::DepositController::SetStartDate(const std::tm& start_date) {
  std::tm date = start_date;
  mktime(&date);
  model_.SetStartDate(date);
}

void s21::DepositController::SetInterest(double interest) {
  model_.SetInterest(interest);
}

void s21::DepositController::SetTax(double tax) { model_.SetTax(tax); }

void s21::DepositController::SetRecurrence(TransactionRecurrence recurrence) {
  model_.SetRecurrence(recurrence);
}

void s21::DepositController::SetCapitalization(bool capitalization) {
  model_.SetCapitalization(capitalization);
}

void s21::DepositController::AddTransactions(
    const std::vector<Transaction>& transactions) {
  model_.AddTransactions(transactions);
}

void s21::DepositController::Calculate() { model_.Calculate(); }

double s21::DepositController::GetTotalInterest() {
  return model_.GetTotalInterest();
}

double s21::DepositController::GetTotalTax() { return model_.GetTotalTax(); }

double s21::DepositController::GetTotalSum() { return model_.GetTotalSum(); }
