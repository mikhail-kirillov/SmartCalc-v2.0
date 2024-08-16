// Copyright 2024 Burr Etienne
#ifndef SRC_VIEW_DEPOSIT_DEPOSIT_H_
#define SRC_VIEW_DEPOSIT_DEPOSIT_H_

#include <QLocale>
#include <QMainWindow>
#include <vector>

#include "../../controller/deposit/deposit.h"
#include "../window.h"

namespace s21 {

class DepositView : public QObject {
  Q_OBJECT

 public:
  explicit DepositView(Ui::main_window* ui = nullptr,
                       QWidget* parent = nullptr);
  ~DepositView();

 private slots:
  void OnDoubleSpinsAmountChanged();
  void OnSpinTermChanged();
  void OnDoubleSpinsInterestChanged();
  void OnDoubleSpinsTaxRateChanged();
  void RadioButtonTermChanged();
  void OnDateEditDepositBeginningChanged();
  void OnCheckBoxCapitalizationChanged();
  void OnComboBoxRecurrenceChanged();
  void OnButtonDeleteClicked();
  void OnButtonWithdrawalClicked();
  void OnButtonReplenishmentClicked();

 private:
  Ui::main_window* ui_ = nullptr;
  QWidget* parent_ = nullptr;
  double total_amount_ = 0;
  int term_ = 0;
  QButtonGroup* radio_button_group_deposit_term_ = nullptr;
  std::tm start_date_ = {};
  std::tm end_date_ = {};
  double interest_rate_ = 0;
  double tax_rate_ = 0;
  bool capitalization_ = false;
  s21::TransactionRecurrence deposit_recurrence_ =
      s21::TransactionRecurrence::ONCE;
  std::vector<s21::Transaction> transactions_ = {};
  double interest_changes_ = 0;
  double tax_amount_ = 0;
  double amount_at_the_end_ = 0;

  void ConnectSpins();
  void ConnectRadioButtons();
  void CalculateTerm();
  void ConnectDateEdit();
  void DataUpdate();
  std::tm QDateToTM(const QDate& date);
  QDate TMToQDate(const std::tm& tm);
  void ConnectCheckBox();
  void ConnectComboBox();
  void SetTableWidget();
  void ConnectButton();
  s21::TransactionRecurrence CountTransactionRecurrenceFromText(QString text);
  void DrawTableFromTransactions();
  void UpdateDataInTransactions();
  QString GetRecurrenceText(TransactionRecurrence recurrence);
  void CalculateDeposit();

  DepositController deposit_controller_;
};

}  // namespace s21

#endif  // SRC_VIEW_DEPOSIT_DEPOSIT_H_
