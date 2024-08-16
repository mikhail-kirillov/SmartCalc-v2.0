// Copyright 2024 Burr Etienne
#include "credit.h"

void s21::CreditController::SetCreditType(CreditType type) {
  model_.SetCreditType(type);
}

void s21::CreditController::SetCreditAmount(double amount) {
  model_.SetCreditAmount(amount);
}

void s21::CreditController::SetCreditTerm(int term) {
  model_.SetCreditTerm(term);
}

void s21::CreditController::SetCreditInterest(double interest) {
  model_.SetCreditInterest(interest);
}

void s21::CreditController::Calculate() { model_.Calculate(); }

double s21::CreditController::GetMonthlyPayment() {
  return model_.GetMonthlyPayment();
}

double s21::CreditController::GetMinMonthlyPayment() {
  return model_.GetMinMonthlyPayment();
}

double s21::CreditController::GetMaxMonthlyPayment() {
  return model_.GetMaxMonthlyPayment();
}

double s21::CreditController::GetTotalPayment() {
  return model_.GetTotalPayment();
}

double s21::CreditController::GetOverpayment() {
  return model_.GetOverpayment();
}
