// Copyright 2024 Burr Etienne
#include "calculator.h"

#include <string>

void s21::CalculatorController::SetExpression(const std::string &expression) {
  model_.SetExpression(expression);
}

void s21::CalculatorController::SetX(double x) { model_.SetX(x); }

void s21::CalculatorController::Calculate() { model_.CalculateExpression(); }

double s21::CalculatorController::GetResult() { return model_.GetResult(); }
