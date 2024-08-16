// Copyright 2024 Burr Etienne
#ifndef SRC_MODEL_GRAPH_GRAPH_H_
#define SRC_MODEL_GRAPH_GRAPH_H_

#include <string>
#include <vector>

#include "../calculator/calculator.h"

namespace s21 {
class GraphModel : private CalculatorModel {
 public:
  GraphModel() = default;
  ~GraphModel() = default;

  void SetExpression(const std::string &expression);
  void SetXMin(double x);
  void SetXMax(double x);
  void SetStep(double step);

  void Calculate();

  std::vector<double> GetXPoints();
  std::vector<double> GetYPoints();

 private:
  double x_min_ = 0;
  double x_max_ = 0;
  double step_ = 0;
  std::vector<double> x_points_ = {};
  std::vector<double> y_points_ = {};

  void CleanPoints();
  void CalculatePoints();

  CalculatorModel calculator_model_;
};
}  // namespace s21

#endif  // SRC_MODEL_GRAPH_GRAPH_H_
