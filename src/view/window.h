// Copyright 2024 Burr Etienne
#ifndef SRC_VIEW_WINDOW_H_
#define SRC_VIEW_WINDOW_H_

#include <QMainWindow>

#include "view/ui_window.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class main_window;
}
QT_END_NAMESPACE

namespace s21 {
class CalculatorView;
class CreditView;
class DepositView;
class GraphView;
}  // namespace s21

namespace s21 {
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private:
  Ui::main_window* ui_;
  s21::CalculatorView* calculator_view_;
  s21::CreditView* credit_view_;
  s21::DepositView* deposit_view_;
  s21::GraphView* graph_view_;
};
}  // namespace s21
#endif  // SRC_VIEW_WINDOW_H_
