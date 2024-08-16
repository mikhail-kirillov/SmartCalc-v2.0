// Copyright 2024 Burr Etienne
#ifndef SRC_VIEW_CREDIT_CREDIT_H_
#define SRC_VIEW_CREDIT_CREDIT_H_

#include <QButtonGroup>
#include <QLocale>
#include <QMainWindow>

#include "../../controller/credit/credit.h"
#include "../window.h"

namespace s21 {

class CreditView : public QObject {
  Q_OBJECT

 public:
  explicit CreditView(Ui::main_window* ui = nullptr);
  ~CreditView();

 private slots:
  void OnDoubleSpinsAmountChanged();
  void OnDoubleSpinsInterestChanged();
  void OnSpinTermChanged();
  void RadioButtonTermChanged();
  void RadioButtonTypeChanged();

 private:
  Ui::main_window* ui_ = nullptr;
  QButtonGroup* radio_button_group_credit_term_ = nullptr;
  QButtonGroup* radio_button_group_credit_type_ = nullptr;
  double total_amount_ = 0;
  double interest_rate_ = 0;
  int term_ = 0;
  CreditType type_ = ANNUITY;
  double overpayment_on_credit_ = 0;
  double total_payment_ = 0;
  double monthly_payment_ = 0;
  double diff_monthly_payment_min_ = 0;
  double diff_monthly_payment_max_ = 0;

  void ConnectSpins();
  void ConnectRadioButtons();
  void CalculateTerm();
  void UpdateAllData();
  void CalculateCredit();

  s21::CreditController credit_controller_;
};

}  // namespace s21

#endif  // SRC_VIEW_CREDIT_CREDIT_H_
