// Copyright 2024 Burr Etienne
#ifndef SRC_MODEL_CALCULATOR_CALCULATOR_H_
#define SRC_MODEL_CALCULATOR_CALCULATOR_H_

#include <stack>
#include <string>

namespace s21 {
class CalculatorModel {
 public:
  CalculatorModel() = default;
  ~CalculatorModel() = default;
  void SetExpression(const std::string &expression);
  void SetX(double x);
  void CalculateExpression();
  double GetResult();

 private:
  struct Lexeme {
    char operation = 0;
    double number = 0;
  };

  std::string expression_ = "";
  double x_ = 0;
  double result_ = 0;
  std::stack<Lexeme> numbers_ = {};
  std::stack<Lexeme> operations_ = {};

  void CleanStacks();
  void ParseExpression();
  std::size_t ReadFunction(const std::string &expression);
  std::size_t ReadNumber(const std::string &expression);
  char ReplaceUnaryOperator(char chr, char previous_char);
  std::size_t ReadOperator(char chr, char *previous_char, std::size_t pos);
  void ReadBracket(char chr);
  std::size_t ReadMod(std::size_t pos);
  int CheckPriority(char chr);
  void CheckXInExpression();

  void Calculate();
  void Function();
  void Binary();
};

}  // namespace s21

#endif  // SRC_MODEL_CALCULATOR_CALCULATOR_H_
