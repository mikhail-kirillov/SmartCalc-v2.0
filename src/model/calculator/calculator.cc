// Copyright 2024 Burr Etienne
#include "calculator.h"

#include <cmath>
#include <cstring>
#include <stdexcept>
#include <utility>

void s21::CalculatorModel::SetExpression(const std::string &expression) {
  expression_ = std::move(expression);
}

void s21::CalculatorModel::SetX(double x) { x_ = x; }

void s21::CalculatorModel::CalculateExpression() {
  setlocale(LC_ALL, "C");
  std::string tmp(expression_);
  CleanStacks();
  CheckXInExpression();
  ParseExpression();
  while (!operations_.empty()) {
    Calculate();
  }
  if (!numbers_.empty()) {
    result_ = numbers_.top().number;
    numbers_.pop();
    if (!numbers_.empty()) {
      throw std::out_of_range("Multiple values in numbers_ stack");
    }
  }
  expression_ = std::move(tmp);
}

double s21::CalculatorModel::GetResult() { return result_; }

void s21::CalculatorModel::CleanStacks() {
  std::stack<Lexeme>().swap(numbers_);
  std::stack<Lexeme>().swap(operations_);
}

void s21::CalculatorModel::ParseExpression() {
  char previous_char = 0;
  std::size_t expression_length = expression_.size();
  for (std::size_t i = 0; i < expression_length; i++) {
    if (std::isspace(expression_[i])) {
      continue;
    } else if (strchr("sctla", expression_[i])) {
      previous_char = expression_[i];
      std::size_t read_chars = ReadFunction(expression_.substr(i));
      if (read_chars != 0) {
        i += read_chars;
      } else {
        throw std::invalid_argument("Invalid Expression! Unknown function");
      }
    } else if (std::isdigit(expression_[i]) || expression_[i] == 'x') {
      if (std::isdigit(previous_char) || previous_char == 'x') {
        throw std::invalid_argument("Invalid Expression! Two numbers in a row");
      } else {
        std::size_t read_chars = ReadNumber(expression_.substr(i));
        i += read_chars;
        previous_char = expression_[i];
      }
    } else if (strchr("+-*/%^", expression_[i])) {
      expression_[i] = ReplaceUnaryOperator(expression_[i], previous_char);
      i = ReadOperator(expression_[i], &previous_char, i);
    } else if (expression_[i] == 'm') {
      i = ReadMod(i);
    } else if (expression_[i] == '(' || expression_[i] == ')') {
      previous_char = expression_[i];
      ReadBracket(expression_[i]);
    } else {
      throw std::invalid_argument("Invalid Expression! Unknown symbol");
    }
  }
}

char s21::CalculatorModel::ReplaceUnaryOperator(char chr, char previous_char) {
  if (!isdigit(previous_char) && previous_char != 'x' && previous_char != ')' &&
      (chr == '+' || chr == '-')) {
    if (chr == '-') {
      chr = '~';
    } else if (chr == '+') {
      chr = '#';
    }
  }
  return chr;
}

std::size_t s21::CalculatorModel::ReadFunction(const std::string &expression) {
  std::size_t read_counter = 0;
  char chr = 0;
  if (expression.compare(0, 4, "sin(") == 0) {
    read_counter += 2;
    chr = 's';
  } else if (expression.compare(0, 4, "cos(") == 0) {
    read_counter += 2;
    chr = 'c';
  } else if (expression.compare(0, 4, "tan(") == 0) {
    read_counter += 2;
    chr = 't';
  } else if (expression.compare(0, 5, "atan(") == 0) {
    read_counter += 3;
    chr = 'T';
  } else if (expression.compare(0, 5, "acos(") == 0) {
    read_counter += 3;
    chr = 'C';
  } else if (expression.compare(0, 5, "asin(") == 0) {
    read_counter += 3;
    chr = 'S';
  } else if (expression.compare(0, 4, "log(") == 0) {
    read_counter += 2;
    chr = 'L';
  } else if (expression.compare(0, 3, "ln(") == 0) {
    read_counter += 1;
    chr = 'l';
  } else if (expression.compare(0, 5, "sqrt(") == 0) {
    read_counter += 3;
    chr = 'q';
  }
  operations_.push({chr, 0});
  return read_counter;
}

std::size_t s21::CalculatorModel::ReadNumber(const std::string &expression) {
  std::size_t read_counter = 0;
  double number = x_;
  if (expression[0] != 'x') {
    number = std::stod(expression, &read_counter);
    read_counter--;
  }
  numbers_.push({0, number});
  return read_counter;
}

std::size_t s21::CalculatorModel::ReadOperator(char chr, char *previous_char,
                                               std::size_t pos) {
  int previous_priority =
      (operations_.empty()) ? 0 : CheckPriority(operations_.top().operation);
  if (previous_priority && CheckPriority(chr) <= previous_priority) {
    Calculate();
    pos--;
  } else {
    *previous_char = chr;
    operations_.push({chr, 0});
  }
  return pos;
}

void s21::CalculatorModel::ReadBracket(char chr) {
  if (chr == '(') {
    operations_.push({chr, 0});
  } else if (chr == ')') {
    if (operations_.empty()) {
      throw std::out_of_range("Invalid Expression! Bracket not found");
    }
    while (operations_.top().operation != '(') {
      Calculate();
      if (operations_.empty()) {
        throw std::out_of_range("Invalid Expression! Bracket not found");
      }
    }
    if (!operations_.empty()) {
      operations_.pop();
    }
  }
}

std::size_t s21::CalculatorModel::ReadMod(std::size_t pos) {
  if (expression_.compare(pos, 3, "mod") == 0) {
    expression_[pos + 2] = '%';
    pos++;
  } else {
    throw std::invalid_argument("Invalid Expression! Mod not found");
  }
  return pos;
}

int s21::CalculatorModel::CheckPriority(char chr) {
  int priority = 0;
  if (chr == '-' || chr == '+') {
    priority = 1;
  } else if (chr == '*' || chr == '/' || chr == '%') {
    priority = 2;
  } else if (chr == '^') {
    priority = 3;
  } else if (chr == 's' || chr == 'c' || chr == 't' || chr == 'T' ||
             chr == 'C' || chr == 'S' || chr == 'L' || chr == 'l' ||
             chr == 'q') {
    priority = 4;
  } else if (chr == '#' || chr == '~') {
    priority = 5;
  }
  return priority;
}

void s21::CalculatorModel::Calculate() {
  if (operations_.empty()) {
    throw std::out_of_range("Invalid Expression! Operations not found");
  }
  char chr = operations_.top().operation;
  if (strchr("+-*/%^", chr)) {
    Binary();
  } else if (strchr("#~sctSCTLlq", chr)) {
    Function();
  } else {
    throw std::invalid_argument("Invalid Expression! Invalid operator");
  }
}

void s21::CalculatorModel::Function() {
  if (numbers_.empty()) {
    throw std::out_of_range("Invalid Expression! Numbers not found");
  }
  char chr = operations_.top().operation;
  operations_.pop();
  double number = numbers_.top().number;
  numbers_.pop();
  double result = 0;
  switch (chr) {
    case 's':
      result = std::sin(number);
      break;
    case 'c':
      result = std::cos(number);
      break;
    case 't':
      result = std::tan(number);
      break;
    case 'S':
      result = std::asin(number);
      break;
    case 'C':
      result = std::acos(number);
      break;
    case 'T':
      result = std::atan(number);
      break;
    case 'L':
      result = std::log10(number);
      break;
    case 'l':
      result = std::log(number);
      break;
    case 'q':
      result = std::sqrt(number);
      break;
    case '~':
      result = -number;
      break;
    case '#':
      result = +number;
      break;
    default:
      throw std::invalid_argument("Invalid Expression");
  }
  if (std::isnan(result)) {
    throw std::invalid_argument("Invalid Expression! Number is NaN");
  }
  numbers_.push({0, result});
}

void s21::CalculatorModel::Binary() {
  if (numbers_.empty() || operations_.empty()) {
    throw std::out_of_range("Invalid Expression! Stacks is empty");
  }
  char chr = operations_.top().operation;
  operations_.pop();
  double number_one = numbers_.top().number;
  numbers_.pop();
  if (numbers_.empty()) {
    throw std::out_of_range("Invalid Expression! Numbers not found");
  }
  double number_two = numbers_.top().number;
  numbers_.pop();
  double result = 0;
  switch (chr) {
    case '+':
      result = number_two + number_one;
      break;
    case '-':
      result = number_two - number_one;
      break;
    case '*':
      result = number_two * number_one;
      break;
    case '/':
      if (number_one == 0) {
        throw std::invalid_argument("Invalid Expression! Division by zero");
      }
      result = number_two / number_one;
      break;
    case '%':
      if (number_one == 0) {
        throw std::invalid_argument("Invalid Expression! Division by zero");
      }
      result = std::fmod(number_two, number_one);
      break;
    case '^':
      result = std::pow(number_two, number_one);
      break;
    default:
      throw std::invalid_argument("Invalid Expression! Invalid Operator");
  }
  if (std::isnan(result)) {
    throw std::invalid_argument("Invalid Expression! Number is NaN");
  }
  numbers_.push({0, result});
}

void s21::CalculatorModel::CheckXInExpression() {
  if (expression_.find('x') != std::string::npos && std::isnan(x_)) {
    throw std::invalid_argument("Invalid Expression! X is not defined");
  }
}
