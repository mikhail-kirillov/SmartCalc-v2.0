// Copyright 2024 Burr Etienne
#include "credit.h"

s21::CreditView::CreditView(Ui::main_window* ui) : ui_(ui) {
  ConnectSpins();
  ConnectRadioButtons();
  UpdateAllData();
  CalculateCredit();
}

s21::CreditView::~CreditView() {
  delete radio_button_group_credit_term_;
  delete radio_button_group_credit_type_;
}

void s21::CreditView::OnDoubleSpinsAmountChanged() {
  total_amount_ = ui_->double_spin_box_credit_amount->value();
  CalculateCredit();
}

void s21::CreditView::OnDoubleSpinsInterestChanged() {
  interest_rate_ = ui_->double_spin_box_credit_interest->value();
  CalculateCredit();
}

void s21::CreditView::OnSpinTermChanged() {
  CalculateTerm();
  CalculateCredit();
}

void s21::CreditView::ConnectSpins() {
  connect(ui_->double_spin_box_credit_amount, &QDoubleSpinBox::valueChanged,
          this, &s21::CreditView::OnDoubleSpinsAmountChanged);
  connect(ui_->double_spin_box_credit_interest, &QDoubleSpinBox::valueChanged,
          this, &s21::CreditView::OnDoubleSpinsInterestChanged);
  connect(ui_->spin_box_credit_term, &QSpinBox::valueChanged, this,
          &s21::CreditView::OnSpinTermChanged);
}

void s21::CreditView::RadioButtonTermChanged() {
  CalculateTerm();
  CalculateCredit();
}

void s21::CreditView::RadioButtonTypeChanged() {
  if (radio_button_group_credit_type_->checkedButton() ==
      ui_->radio_button_credit_type_annuity) {
    type_ = ANNUITY;
  } else if (radio_button_group_credit_type_->checkedButton() ==
             ui_->radio_button_credit_type_differential) {
    type_ = DIFFERENTIAL;
  }
  CalculateCredit();
}

void s21::CreditView::ConnectRadioButtons() {
  radio_button_group_credit_term_ = new QButtonGroup(this);
  radio_button_group_credit_term_->addButton(
      ui_->radio_button_credit_term_months, 1);
  radio_button_group_credit_term_->addButton(
      ui_->radio_button_credit_term_years, 2);
  connect(radio_button_group_credit_term_, &QButtonGroup::buttonClicked, this,
          &s21::CreditView::RadioButtonTermChanged);

  radio_button_group_credit_type_ = new QButtonGroup(this);
  radio_button_group_credit_type_->addButton(
      ui_->radio_button_credit_type_annuity, 1);
  radio_button_group_credit_type_->addButton(
      ui_->radio_button_credit_type_differential, 2);
  connect(radio_button_group_credit_type_, &QButtonGroup::buttonClicked, this,
          &s21::CreditView::RadioButtonTypeChanged);
}

void s21::CreditView::CalculateTerm() {
  int tmp_term = ui_->spin_box_credit_term->value();
  int term = 0;
  if (radio_button_group_credit_term_->checkedButton() ==
      ui_->radio_button_credit_term_months) {
    term = tmp_term;
  } else if (radio_button_group_credit_term_->checkedButton() ==
             ui_->radio_button_credit_term_years) {
    term = 12 * tmp_term;
  }
  term_ = term;
}

void s21::CreditView::UpdateAllData() {
  OnDoubleSpinsAmountChanged();
  OnDoubleSpinsInterestChanged();
  OnSpinTermChanged();
  RadioButtonTermChanged();
  RadioButtonTypeChanged();
}

void s21::CreditView::CalculateCredit() {
  try {
    credit_controller_.SetCreditType(type_);
    credit_controller_.SetCreditAmount(total_amount_);
    credit_controller_.SetCreditTerm(term_);
    credit_controller_.SetCreditInterest(interest_rate_);

    credit_controller_.Calculate();

    double overpayment_on_credit = credit_controller_.GetOverpayment();
    double total_payment = credit_controller_.GetTotalPayment();
    double monthly_payment = credit_controller_.GetMonthlyPayment();
    double diff_monthly_payment_min = credit_controller_.GetMinMonthlyPayment();
    double diff_monthly_payment_max = credit_controller_.GetMaxMonthlyPayment();

    QLocale locale(QLocale::French);
    QString formatted_number = locale.toString(overpayment_on_credit, 'f', 2);
    ui_->line_edit_credit_overpayment->setText(formatted_number);
    formatted_number = locale.toString(total_payment, 'f', 2);
    ui_->line_edit_credit_total_payment->setText(formatted_number);

    if (type_ == ANNUITY) {
      formatted_number = locale.toString(monthly_payment, 'f', 2);
      ui_->line_edit_credit_monthly_payment->setText(formatted_number);
    } else if (type_ == DIFFERENTIAL) {
      QString formatted_number_min =
          locale.toString(diff_monthly_payment_min, 'f', 2);
      QString formatted_number_max =
          locale.toString(diff_monthly_payment_max, 'f', 2);
      ui_->line_edit_credit_monthly_payment->setText(
          formatted_number_min + " ... " + formatted_number_max);
    }
  } catch (const std::exception& e) {
    ui_->line_edit_credit_overpayment->setText(
        "Error: " + QString::fromStdString(e.what()));
    ui_->line_edit_credit_total_payment->setText(
        "Error: " + QString::fromStdString(e.what()));
    ui_->line_edit_credit_monthly_payment->setText(
        "Error: " + QString::fromStdString(e.what()));
  }
}
