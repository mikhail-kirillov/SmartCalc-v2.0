// Copyright 2024 Burr Etienne
#include "window.h"

#include "calculator/calculator.h"
#include "credit/credit.h"
#include "deposit/deposit.h"
#include "graph/graph.h"

s21::MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui_(new Ui::main_window) {
  ui_->setupUi(this);
  calculator_view_ = new s21::CalculatorView(ui_);
  credit_view_ = new s21::CreditView(ui_);
  deposit_view_ = new s21::DepositView(ui_, this);
  graph_view_ = new s21::GraphView(ui_);
}

s21::MainWindow::~MainWindow() {
  delete ui_;
  delete calculator_view_;
  delete credit_view_;
  delete deposit_view_;
  delete graph_view_;
}
