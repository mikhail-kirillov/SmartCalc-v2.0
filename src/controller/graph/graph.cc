// Copyright 2024 Burr Etienne
#include "graph.h"

void s21::GraphController::SetExpression(const std::string &expression) {
  graph_model_.SetExpression(expression);
}

void s21::GraphController::SetXMin(double x) { graph_model_.SetXMin(x); }

void s21::GraphController::SetXMax(double x) { graph_model_.SetXMax(x); }

void s21::GraphController::SetStep(double step) { graph_model_.SetStep(step); }

void s21::GraphController::Calculate() { graph_model_.Calculate(); }

std::vector<double> s21::GraphController::GetXPoints() {
  return graph_model_.GetXPoints();
}

std::vector<double> s21::GraphController::GetYPoints() {
  return graph_model_.GetYPoints();
}
