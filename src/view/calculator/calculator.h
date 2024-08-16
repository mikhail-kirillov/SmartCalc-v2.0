// Copyright 2024 Burr Etienne
#ifndef SRC_VIEW_CALCULATOR_CALCULATOR_H_
#define SRC_VIEW_CALCULATOR_CALCULATOR_H_

#include <QMainWindow>

#include "../../controller/calculator/calculator.h"
#include "../window.h"

namespace s21 {

class CalculatorView : public QObject {
  Q_OBJECT

 public:
  explicit CalculatorView(Ui::main_window* ui = nullptr);
  ~CalculatorView();

 private slots:
  void OnButtonsClicked();
  void OnButtonClearClicked();
  void OnButtonDeleteClicked();
  void OnButtonResultClicked();
  void LineEditInputValidator(QLineEdit* line_edit);

 private:
  Ui::main_window* ui_ = nullptr;
  QMap<QPushButton*, QString> push_buttons_calculator_map_ = {};
  QRegularExpressionValidator* line_edit_calculator_expression_validator_ =
      nullptr;
  QRegularExpressionValidator* line_edit_calculator_x_validator_ = nullptr;

  void ConnectButtons();
  void LineEditConnectValidator();

  s21::CalculatorController calculator_controller_;
};

}  // namespace s21

#endif  // SRC_VIEW_CALCULATOR_CALCULATOR_H_
