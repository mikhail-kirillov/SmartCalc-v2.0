// Copyright 2024 Burr Etienne
#include "calculator.h"

#include <QRegularExpressionValidator>
#include <QtCore/QRegularExpression>
#include <limits>
#include <string>

s21::CalculatorView::CalculatorView(Ui::main_window* ui) : ui_(ui) {
  ConnectButtons();
  LineEditConnectValidator();
  ui_->line_edit_calculator_expression->setFocus();
}

s21::CalculatorView::~CalculatorView() {
  delete line_edit_calculator_x_validator_;
  delete line_edit_calculator_expression_validator_;
}

void s21::CalculatorView::LineEditConnectValidator() {
  connect(ui_->line_edit_calculator_expression, &QLineEdit::textChanged, this,
          [this]() {
            LineEditInputValidator(ui_->line_edit_calculator_expression);
          });
  connect(ui_->line_edit_calculator_x, &QLineEdit::textChanged, this,
          [this]() { LineEditInputValidator(ui_->line_edit_calculator_x); });
}

void s21::CalculatorView::ConnectButtons() {
  push_buttons_calculator_map_[ui_->push_button_calculator_one] = "1";
  push_buttons_calculator_map_[ui_->push_button_calculator_two] = "2";
  push_buttons_calculator_map_[ui_->push_button_calculator_three] = "3";
  push_buttons_calculator_map_[ui_->push_button_calculator_four] = "4";
  push_buttons_calculator_map_[ui_->push_button_calculator_five] = "5";
  push_buttons_calculator_map_[ui_->push_button_calculator_six] = "6";
  push_buttons_calculator_map_[ui_->push_button_calculator_seven] = "7";
  push_buttons_calculator_map_[ui_->push_button_calculator_eight] = "8";
  push_buttons_calculator_map_[ui_->push_button_calculator_nine] = "9";
  push_buttons_calculator_map_[ui_->push_button_calculator_zero] = "0";
  push_buttons_calculator_map_[ui_->push_button_calculator_plus] = "+";
  push_buttons_calculator_map_[ui_->push_button_calculator_minus] = "-";
  push_buttons_calculator_map_[ui_->push_button_calculator_div] = "/";
  push_buttons_calculator_map_[ui_->push_button_calculator_mul] = "*";
  push_buttons_calculator_map_[ui_->push_button_calculator_bracket_left] = "(";
  push_buttons_calculator_map_[ui_->push_button_calculator_bracket_right] = ")";
  push_buttons_calculator_map_[ui_->push_button_calculator_mod] = "mod";
  push_buttons_calculator_map_[ui_->push_button_calculator_pow] = "^";
  push_buttons_calculator_map_[ui_->push_button_calculator_sin] = "sin(";
  push_buttons_calculator_map_[ui_->push_button_calculator_cos] = "cos(";
  push_buttons_calculator_map_[ui_->push_button_calculator_asin] = "asin(";
  push_buttons_calculator_map_[ui_->push_button_calculator_acos] = "acos(";
  push_buttons_calculator_map_[ui_->push_button_calculator_tan] = "tan(";
  push_buttons_calculator_map_[ui_->push_button_calculator_atan] = "atan(";
  push_buttons_calculator_map_[ui_->push_button_calculator_log] = "log(";
  push_buttons_calculator_map_[ui_->push_button_calculator_ln] = "ln(";
  push_buttons_calculator_map_[ui_->push_button_calculator_x] = "x";
  push_buttons_calculator_map_[ui_->push_button_calculator_e] = "e";
  push_buttons_calculator_map_[ui_->push_button_calculator_point] = ".";
  push_buttons_calculator_map_[ui_->push_button_calculator_sqrt] = "sqrt(";
  for (auto it = push_buttons_calculator_map_.begin();
       it != push_buttons_calculator_map_.end(); ++it) {
    connect(it.key(), &QPushButton::clicked, this,
            &s21::CalculatorView::OnButtonsClicked);
  }

  connect(ui_->push_button_calculator_clear, &QPushButton::clicked, this,
          &s21::CalculatorView::OnButtonClearClicked);
  connect(ui_->push_button_calculator_delete, &QPushButton::clicked, this,
          &s21::CalculatorView::OnButtonDeleteClicked);
  connect(ui_->push_button_calculator_result, &QPushButton::clicked, this,
          &s21::CalculatorView::OnButtonResultClicked);
}

void s21::CalculatorView::OnButtonsClicked() {
  QPushButton* button = qobject_cast<QPushButton*>(sender());

  if (button != nullptr) {
    QLineEdit* focused_line_edit = nullptr;

    if (ui_->line_edit_calculator_expression->hasFocus()) {
      focused_line_edit = ui_->line_edit_calculator_expression;
    } else if (ui_->line_edit_calculator_x->hasFocus()) {
      focused_line_edit = ui_->line_edit_calculator_x;
    }

    if (focused_line_edit != nullptr) {
      QString current_text = focused_line_edit->text();
      QString button_text = push_buttons_calculator_map_[button];
      current_text.append(button_text);
      focused_line_edit->setText(current_text);
    }
  }
}

void s21::CalculatorView::LineEditInputValidator(QLineEdit* line_edit) {
  QRegularExpression regex{};
  QString text = "";
  if (line_edit == ui_->line_edit_calculator_expression) {
    text = line_edit->text();
    regex =
        QRegularExpression("^[\\d\\+\\-\\/\\*\\(\\)\\^e\\.xasincotlgsqrmd]*$");
  } else if (line_edit == ui_->line_edit_calculator_x) {
    text = line_edit->text();
    regex = QRegularExpression("^[+-]?\\d*\\.?\\d*(e[+-]?\\d*)?$");
  }
  if (!regex.match(text, 0, QRegularExpression::PartialPreferCompleteMatch)
           .hasMatch()) {
    if (!text.isEmpty()) {
      text.chop(1);
      line_edit->setText(text);
    }
  }
}

void s21::CalculatorView::OnButtonClearClicked() {
  QLineEdit* focused_line_edit = nullptr;

  if (ui_->line_edit_calculator_expression->hasFocus()) {
    focused_line_edit = ui_->line_edit_calculator_expression;
  } else if (ui_->line_edit_calculator_x->hasFocus()) {
    focused_line_edit = ui_->line_edit_calculator_x;
  }

  if (focused_line_edit != nullptr) {
    focused_line_edit->clear();
  }
  ui_->label_calculator_error->setText("");
}

void s21::CalculatorView::OnButtonDeleteClicked() {
  QLineEdit* focused_line_edit = nullptr;

  if (ui_->line_edit_calculator_expression->hasFocus()) {
    focused_line_edit = ui_->line_edit_calculator_expression;
  } else if (ui_->line_edit_calculator_x->hasFocus()) {
    focused_line_edit = ui_->line_edit_calculator_x;
  }

  if (focused_line_edit != nullptr) {
    QString current_text = focused_line_edit->text();
    if (!current_text.isEmpty()) {
      current_text.chop(1);
      focused_line_edit->setText(current_text);
    }
  }
}

void s21::CalculatorView::OnButtonResultClicked() {
  QString expression = ui_->line_edit_calculator_expression->text();

  if (!expression.isEmpty()) {
    std::string std_expression = expression.toStdString();
    calculator_controller_.SetExpression(std_expression);

    double x = 0;
    QString x_number = ui_->line_edit_calculator_x->text();
    if (!x_number.isEmpty()) {
      bool is_x_normal = false;
      x = ui_->line_edit_calculator_x->text().toDouble(&is_x_normal);

      if (!is_x_normal) {
        ui_->label_calculator_error->setText("Error! Invalid X");
      }

    } else {
      x = std::numeric_limits<double>::quiet_NaN();
    }

    calculator_controller_.SetX(x);
    try {
      calculator_controller_.Calculate();
      ui_->line_edit_calculator_expression->setText(
          QString::number(calculator_controller_.GetResult(), 'g', 7)
              .replace(',', '.')
              .replace('E', 'e'));
      ui_->label_calculator_error->setText("");
    } catch (const std::out_of_range& e) {
      ui_->label_calculator_error->setText(e.what());
    } catch (const std::invalid_argument& e) {
      ui_->label_calculator_error->setText(e.what());
    } catch (...) {
      ui_->label_calculator_error->setText("Error! Unknown error occurred");
    }
  }
}
