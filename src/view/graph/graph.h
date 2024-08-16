// Copyright 2024 Burr Etienne
#ifndef SRC_VIEW_GRAPH_GRAPH_H_
#define SRC_VIEW_GRAPH_GRAPH_H_

#include <QMainWindow>

#include "../../controller/graph/graph.h"
#include "../window.h"

namespace s21 {

class GraphView : public QObject {
  Q_OBJECT

 public:
  explicit GraphView(Ui::main_window* ui = nullptr);
  ~GraphView() = default;

 private slots:
  void OnDrawButtonClicked();

 private:
  Ui::main_window* ui_ = nullptr;
  double x_min_ = 0;
  double x_max_ = 0;
  double y_min_ = 0;
  double y_max_ = 0;
  double step_ = 0;

  void ConnectDrawButton();
  void DrawGraph();
  void GetValues();

  GraphController graph_controller_;
};

}  // namespace s21

#endif  // SRC_VIEW_GRAPH_GRAPH_H_
