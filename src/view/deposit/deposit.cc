// Copyright 2024 Burr Etienne
#include "deposit.h"

s21::DepositView::DepositView(Ui::main_window* ui, QWidget* parent)
    : ui_(ui), parent_(parent) {
  ConnectSpins();
  ConnectRadioButtons();
  CalculateTerm();
  ConnectDateEdit();
  ConnectCheckBox();
  ConnectComboBox();
  SetTableWidget();
  ConnectButton();
  OnDoubleSpinsAmountChanged();
  OnSpinTermChanged();
  OnDoubleSpinsInterestChanged();
  OnDoubleSpinsTaxRateChanged();
  RadioButtonTermChanged();
  OnDateEditDepositBeginningChanged();
  OnCheckBoxCapitalizationChanged();
  OnComboBoxRecurrenceChanged();
  CalculateDeposit();
}

s21::DepositView::~DepositView() { delete radio_button_group_deposit_term_; }

void s21::DepositView::OnDoubleSpinsAmountChanged() {
  total_amount_ = ui_->double_spin_box_deposit_amount->value();
  CalculateDeposit();
}

void s21::DepositView::OnSpinTermChanged() { DataUpdate(); }

void s21::DepositView::OnDoubleSpinsInterestChanged() {
  interest_rate_ = ui_->double_spin_box_deposit_interest_rate->value();
  CalculateDeposit();
}

void s21::DepositView::OnDoubleSpinsTaxRateChanged() {
  tax_rate_ = ui_->double_spin_box_deposit_tax_rate->value();
  CalculateDeposit();
}

void s21::DepositView::ConnectSpins() {
  connect(ui_->double_spin_box_deposit_amount, &QDoubleSpinBox::valueChanged,
          this, &s21::DepositView::OnDoubleSpinsAmountChanged);
  connect(ui_->spin_box_deposit_term, &QSpinBox::valueChanged, this,
          &s21::DepositView::OnSpinTermChanged);
  connect(ui_->double_spin_box_deposit_interest_rate,
          &QDoubleSpinBox::valueChanged, this,
          &s21::DepositView::OnDoubleSpinsInterestChanged);
  connect(ui_->double_spin_box_deposit_tax_rate, &QDoubleSpinBox::valueChanged,
          this, &s21::DepositView::OnDoubleSpinsTaxRateChanged);
}

void s21::DepositView::CalculateTerm() {
  int tmp_term = ui_->spin_box_deposit_term->value();
  int term = 0;
  if (radio_button_group_deposit_term_->checkedButton() ==
      ui_->radio_button_deposit_term_months) {
    term = tmp_term;
  } else if (radio_button_group_deposit_term_->checkedButton() ==
             ui_->radio_button_deposit_term_years) {
    term = 12 * tmp_term;
  }
  term_ = term;
}

void s21::DepositView::RadioButtonTermChanged() { DataUpdate(); }

void s21::DepositView::ConnectRadioButtons() {
  radio_button_group_deposit_term_ = new QButtonGroup(this);
  radio_button_group_deposit_term_->addButton(
      ui_->radio_button_deposit_term_months, 1);
  radio_button_group_deposit_term_->addButton(
      ui_->radio_button_deposit_term_years, 2);
  connect(radio_button_group_deposit_term_, &QButtonGroup::buttonClicked, this,
          &s21::DepositView::RadioButtonTermChanged);
}

std::tm s21::DepositView::QDateToTM(const QDate& date) {
  std::tm tm = {};
  tm.tm_year = date.year() - 1900;
  tm.tm_mon = date.month() - 1;
  tm.tm_mday = date.day();
  mktime(&tm);
  return tm;
}

QDate s21::DepositView::TMToQDate(const std::tm& tm) {
  QDate date = QDate(tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
  return date;
}

void s21::DepositView::DataUpdate() {
  CalculateTerm();
  QDate start_date = ui_->date_edit_deposit_beginning_date->date();
  start_date_ = QDateToTM(start_date);
  std::tm tm = start_date_;
  tm.tm_mon += term_;
  mktime(&tm);
  end_date_ = tm;

  QDate end_date = start_date.addMonths(term_).addDays(-1);
  ui_->date_edit_deposit_w_r_date->setMinimumDate(start_date.addDays(1));
  ui_->date_edit_deposit_w_r_date->setMaximumDate(end_date);
  CalculateDeposit();
}

void s21::DepositView::OnDateEditDepositBeginningChanged() { DataUpdate(); }

void s21::DepositView::ConnectDateEdit() {
  connect(ui_->date_edit_deposit_beginning_date, &QDateEdit::dateChanged, this,
          &s21::DepositView::OnDateEditDepositBeginningChanged);
}

void s21::DepositView::OnCheckBoxCapitalizationChanged() {
  capitalization_ = ui_->check_box_deposit_interest_capitalization->isChecked();
  ui_->combo_box_deposit_recurrence->blockSignals(true);

  if (capitalization_) {
    ui_->combo_box_deposit_recurrence->setItemData(0, 0, Qt::UserRole - 1);
    if (ui_->combo_box_deposit_recurrence->currentIndex() == 0) {
      ui_->combo_box_deposit_recurrence->setCurrentIndex(1);
    }
  } else {
    ui_->combo_box_deposit_recurrence->setItemData(0, QVariant(),
                                                   Qt::UserRole - 1);
  }

  ui_->combo_box_deposit_recurrence->blockSignals(false);
  CalculateDeposit();
}

void s21::DepositView::ConnectCheckBox() {
  connect(ui_->check_box_deposit_interest_capitalization,
          &QCheckBox::stateChanged, this,
          &s21::DepositView::OnCheckBoxCapitalizationChanged);
}

void s21::DepositView::OnComboBoxRecurrenceChanged() {
  deposit_recurrence_ = static_cast<s21::TransactionRecurrence>(
      ui_->combo_box_deposit_recurrence->currentData().toInt());
  CalculateDeposit();
}

void s21::DepositView::ConnectComboBox() {
  ui_->combo_box_deposit_recurrence->addItem("Once", 0);
  ui_->combo_box_deposit_recurrence->addItem("Daily", 1);
  ui_->combo_box_deposit_recurrence->addItem("Monthly", 2);
  connect(ui_->combo_box_deposit_recurrence, &QComboBox::currentIndexChanged,
          this, &s21::DepositView::OnComboBoxRecurrenceChanged);

  ui_->combo_box_deposit_w_r_recurrence->addItem("Once", 0);
  ui_->combo_box_deposit_w_r_recurrence->addItem("Monthly", 2);
}

void s21::DepositView::SetTableWidget() {
  ui_->table_widget_deposit_w_r->verticalHeader()->setVisible(false);
  ui_->table_widget_deposit_w_r->setColumnCount(3);
  QStringList headers;
  headers << "Recurrence" << "Date" << "Amount";
  ui_->table_widget_deposit_w_r->setHorizontalHeaderLabels(headers);
  ui_->table_widget_deposit_w_r->setSelectionBehavior(
      QAbstractItemView::SelectRows);
  ui_->table_widget_deposit_w_r->setSelectionMode(
      QAbstractItemView::SingleSelection);
  ui_->table_widget_deposit_w_r->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);
}

void s21::DepositView::DrawTableFromTransactions() {
  UpdateDataInTransactions();
  ui_->table_widget_deposit_w_r->clearContents();
  ui_->table_widget_deposit_w_r->setRowCount(transactions_.size());

  for (auto i = 0; i < transactions_.size(); ++i) {
    const auto& transaction = transactions_[i];

    QTableWidgetItem* recurrence_item =
        new QTableWidgetItem(GetRecurrenceText(transaction.recurrence));
    QTableWidgetItem* date_item =
        new QTableWidgetItem(QString("%1.%2.%3")
                                 .arg(transaction.date.tm_mday)
                                 .arg(transaction.date.tm_mon + 1)
                                 .arg(transaction.date.tm_year + 1900));
    QTableWidgetItem* amount_item =
        new QTableWidgetItem(QString::number(transaction.amount, 'g', 2));

    ui_->table_widget_deposit_w_r->setItem(i, 0, recurrence_item);
    ui_->table_widget_deposit_w_r->setItem(i, 1, date_item);
    ui_->table_widget_deposit_w_r->setItem(i, 2, amount_item);
  }
  CalculateDeposit();
}

QString s21::DepositView::GetRecurrenceText(TransactionRecurrence recurrence) {
  QString result = "";
  if (recurrence == TransactionRecurrence::ONCE) {
    result = "Once";
  } else if (recurrence == TransactionRecurrence::DAILY) {
    result = "Daily";
  } else if (recurrence == TransactionRecurrence::MONTHLY) {
    result = "Monthly";
  } else {
    result = "Unknown";
  }
  return result;
}

s21::TransactionRecurrence s21::DepositView::CountTransactionRecurrenceFromText(
    QString text) {
  s21::TransactionRecurrence result = s21::TransactionRecurrence::ONCE;
  if (text == "Once") {
    result = s21::TransactionRecurrence::ONCE;
  } else if (text == "Daily") {
    result = s21::TransactionRecurrence::DAILY;
  } else if (text == "Monthly") {
    result = s21::TransactionRecurrence::MONTHLY;
  }
  return result;
}

void s21::DepositView::OnButtonDeleteClicked() {
  int selected_row = ui_->table_widget_deposit_w_r->currentRow();
  if (selected_row >= 0 &&
      selected_row < static_cast<int>(transactions_.size())) {
    auto temp_transaction = transactions_[selected_row];

    transactions_.erase(transactions_.begin() + selected_row);

    deposit_controller_.SetAmount(total_amount_);
    deposit_controller_.SetTerm(term_);
    deposit_controller_.SetStartDate(start_date_);
    deposit_controller_.SetInterest(interest_rate_);
    deposit_controller_.SetTax(tax_rate_);
    deposit_controller_.SetRecurrence(deposit_recurrence_);
    deposit_controller_.SetCapitalization(capitalization_);
    deposit_controller_.AddTransactions(transactions_);

    deposit_controller_.Calculate();

    double amount_at_the_end = deposit_controller_.GetTotalSum();

    // Если депозит становится отрицательным, возвращаем транзакцию назад
    if (amount_at_the_end <= 0) {
      transactions_.insert(transactions_.begin() + selected_row,
                           temp_transaction);
      QMessageBox::warning(
          parent_, "Error",
          "Deleting this transaction will result in a negative deposit");
    } else {
      DrawTableFromTransactions();
    }
  }
}

void s21::DepositView::OnButtonWithdrawalClicked() {
  s21::Transaction tmp_transaction = s21::Transaction{
      QDateToTM(ui_->date_edit_deposit_w_r_date->date()),
      (-1 * (ui_->double_spin_box_deposit_sum->value())),
      static_cast<s21::TransactionRecurrence>(
          CountTransactionRecurrenceFromText(
              ui_->combo_box_deposit_w_r_recurrence->currentText()))};
  transactions_.push_back(tmp_transaction);
  DrawTableFromTransactions();
}

void s21::DepositView::OnButtonReplenishmentClicked() {
  s21::Transaction tmp_transaction = s21::Transaction{
      QDateToTM(ui_->date_edit_deposit_w_r_date->date()),
      (ui_->double_spin_box_deposit_sum->value()),
      static_cast<s21::TransactionRecurrence>(
          CountTransactionRecurrenceFromText(
              ui_->combo_box_deposit_w_r_recurrence->currentText()))};
  transactions_.push_back(tmp_transaction);
  DrawTableFromTransactions();
}

void s21::DepositView::ConnectButton() {
  connect(ui_->push_button_deposit_table_withdrawal, &QPushButton::clicked,
          this, &s21::DepositView::OnButtonWithdrawalClicked);
  connect(ui_->push_button_deposit_table_replenishment, &QPushButton::clicked,
          this, &s21::DepositView::OnButtonReplenishmentClicked);
  connect(ui_->push_button_deposit_table_delete, &QPushButton::clicked, this,
          &s21::DepositView::OnButtonDeleteClicked);
}

void s21::DepositView::UpdateDataInTransactions() {
  for (auto it = transactions_.begin(); it != transactions_.end();) {
    if (mktime(&(*it).date) <= mktime(&start_date_) ||
        mktime(&(*it).date) >= mktime(&end_date_)) {
      it = transactions_.erase(it);
    } else {
      ++it;
    }
  }
}

void s21::DepositView::CalculateDeposit() {
  try {
    deposit_controller_.SetAmount(total_amount_);
    deposit_controller_.SetTerm(term_);
    deposit_controller_.SetStartDate(start_date_);
    deposit_controller_.SetInterest(interest_rate_);
    deposit_controller_.SetTax(tax_rate_);
    deposit_controller_.SetRecurrence(deposit_recurrence_);
    deposit_controller_.SetCapitalization(capitalization_);
    deposit_controller_.AddTransactions(transactions_);
    deposit_controller_.Calculate();

    interest_changes_ = deposit_controller_.GetTotalInterest();
    tax_amount_ = deposit_controller_.GetTotalTax();
    amount_at_the_end_ = deposit_controller_.GetTotalSum();

    QLocale locale(QLocale::French);
    QString formatted_number = locale.toString(interest_changes_, 'f', 2);
    ui_->line_edit_deposit_interest_charges->setText(formatted_number);
    formatted_number = locale.toString(tax_amount_, 'f', 2);
    ui_->line_edit_deposit_tax_amount->setText(formatted_number);
    formatted_number = locale.toString(amount_at_the_end_, 'f', 2);
    ui_->line_edit_deposit_amount_at_the_end->setText(formatted_number);
  } catch (const std::exception& e) {
    ui_->line_edit_deposit_interest_charges->setText(
        "Error: " + QString::fromStdString(e.what()));
    ui_->line_edit_deposit_tax_amount->setText(
        "Error: " + QString::fromStdString(e.what()));
    ui_->line_edit_deposit_amount_at_the_end->setText(
        "Error: " + QString::fromStdString(e.what()));
  }

  if (amount_at_the_end_ - ui_->double_spin_box_deposit_sum->value() <= 0) {
    ui_->push_button_deposit_table_withdrawal->setEnabled(false);
  } else {
    ui_->push_button_deposit_table_withdrawal->setEnabled(true);
  }
}
