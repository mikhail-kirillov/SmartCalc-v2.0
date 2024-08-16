// Copyright 2024 Burr Etienne
#ifndef SRC_CONTROLLER_GRAPH_GRAPH_H_
#define SRC_CONTROLLER_GRAPH_GRAPH_H_

#include <string>
#include <vector>

#include "../../model/graph/graph.h"

namespace s21 {
class GraphController {
 public:
  GraphController() = default;
  ~GraphController() = default;
  void SetExpression(const std::string &expression);
  void SetXMin(double x);
  void SetXMax(double x);
  void SetStep(double step);
  void Calculate();
  std::vector<double> GetXPoints();
  std::vector<double> GetYPoints();

 private:
  GraphModel graph_model_;
};
}  // namespace s21

#endif  // SRC_CONTROLLER_GRAPH_GRAPH_H_
