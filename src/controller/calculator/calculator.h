// Copyright 2024 Burr Etienne
#ifndef SRC_CONTROLLER_CALCULATOR_CALCULATOR_H_
#define SRC_CONTROLLER_CALCULATOR_CALCULATOR_H_

#include <string>

#include "../../model/calculator/calculator.h"

namespace s21 {

class CalculatorController {
 public:
  CalculatorController() = default;
  ~CalculatorController() = default;

  void SetExpression(const std::string &expression);
  void SetX(double x);
  void Calculate();
  double GetResult();

 private:
  CalculatorModel model_;
};

}  // namespace s21

#endif  // SRC_CONTROLLER_CALCULATOR_CALCULATOR_H_
