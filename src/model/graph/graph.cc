// Copyright 2024 Burr Etienne
#include "graph.h"

#include <string>

void s21::GraphModel::SetExpression(const std::string &expression) {
  calculator_model_.SetExpression(expression);
}

void s21::GraphModel::SetXMin(double x) { x_min_ = x; }

void s21::GraphModel::SetXMax(double x) { x_max_ = x; }

void s21::GraphModel::SetStep(double step) { step_ = step; }

void s21::GraphModel::Calculate() {
  CleanPoints();
  CalculatePoints();
}

std::vector<double> s21::GraphModel::GetXPoints() { return x_points_; }

std::vector<double> s21::GraphModel::GetYPoints() { return y_points_; }

void s21::GraphModel::CleanPoints() {
  x_points_.clear();
  y_points_.clear();
}

void s21::GraphModel::CalculatePoints() {
  for (double x = x_min_; x <= x_max_; x += step_) {
    calculator_model_.SetX(x);
    calculator_model_.CalculateExpression();
    x_points_.push_back(x);
    y_points_.push_back(calculator_model_.GetResult());
  }
}
