// Copyright 2024 Burr Etienne
#include "credit.h"

#include <cmath>

void s21::CreditModel::SetCreditType(CreditType type) { type_ = type; }

void s21::CreditModel::SetCreditAmount(double amount) { amount_ = amount; }

void s21::CreditModel::SetCreditTerm(int term) { term_ = term; }

void s21::CreditModel::SetCreditInterest(double interest) {
  interest_ = interest;
}

void s21::CreditModel::Calculate() {
  NullableCalculation();
  monthly_interest_ = (interest_ / 12) * 0.01;
  if (type_ == CreditType::ANNUITY) {
    CalculateAnnuity();
  } else if (type_ == CreditType::DIFFERENTIAL) {
    CalculateDifferential();
  }
  overpayment_ = total_payment_ - amount_;
}

double s21::CreditModel::GetMonthlyPayment() { return monthly_payment_; }

double s21::CreditModel::GetMinMonthlyPayment() { return min_monthly_payment_; }

double s21::CreditModel::GetMaxMonthlyPayment() { return max_monthly_payment_; }

double s21::CreditModel::GetTotalPayment() { return total_payment_; }

double s21::CreditModel::GetOverpayment() { return overpayment_; }

void s21::CreditModel::CalculateAnnuity() {
  double credit_factor = pow(1 + monthly_interest_, term_);
  monthly_payment_ =
      amount_ * monthly_interest_ * credit_factor / (credit_factor - 1);
  total_payment_ = monthly_payment_ * term_;
}

void s21::CreditModel::CalculateDifferential() {
  for (int i = 1; i <= term_; i++) {
    double raw_monthly_payment = amount_ / term_;
    double rate_monthly_payment =
        (amount_ - (i - 1) * raw_monthly_payment) * monthly_interest_;

    double monthly_payment = raw_monthly_payment + rate_monthly_payment;

    if (i == 1) {
      min_monthly_payment_ = monthly_payment;
    } else if (i == term_) {
      max_monthly_payment_ = monthly_payment;
    }

    total_payment_ += monthly_payment;
  }
}

void s21::CreditModel::NullableCalculation() {
  monthly_payment_ = 0;
  min_monthly_payment_ = 0;
  max_monthly_payment_ = 0;
  total_payment_ = 0;
  overpayment_ = 0;
  monthly_interest_ = 0;
}
