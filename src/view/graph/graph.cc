// Copyright 2024 Burr Etienne
#include "graph.h"

#include <vector>

s21::GraphView::GraphView(Ui::main_window* ui) : ui_(ui) {
  ConnectDrawButton();
  GetValues();
}

void s21::GraphView::ConnectDrawButton() {
  connect(ui_->push_button_graph_draw, &QPushButton::clicked, this,
          &s21::GraphView::OnDrawButtonClicked);
}

void s21::GraphView::OnDrawButtonClicked() {
  GetValues();
  DrawGraph();
}

void s21::GraphView::GetValues() {
  x_min_ = ui_->spin_box_deposit_x_axis_min->value();
  x_max_ = ui_->spin_box_deposit_x_axis_max->value();
  y_min_ = ui_->spin_box_deposit_y_axis_min->value();
  y_max_ = ui_->spin_box_deposit_y_axis_max->value();
  step_ = (x_max_ - x_min_) / 1000000;
}

void s21::GraphView::DrawGraph() {
  if (!ui_->line_edit_calculator_expression->text().isEmpty()) {
    ui_->widget_graph->clearGraphs();

    graph_controller_.SetExpression(
        ui_->line_edit_calculator_expression->text().toStdString());
    graph_controller_.SetXMin(x_min_);
    graph_controller_.SetXMax(x_max_);
    graph_controller_.SetStep(step_);

    try {
      graph_controller_.Calculate();

      std::vector<double> x_vector = graph_controller_.GetXPoints();
      std::vector<double> y_vector = graph_controller_.GetYPoints();

      ui_->widget_graph->xAxis->setRange(x_min_, x_max_);
      ui_->widget_graph->yAxis->setRange(y_min_, y_max_);
      ui_->widget_graph->xAxis->setLabel("X");
      ui_->widget_graph->yAxis->setLabel("Y");

      ui_->widget_graph->addGraph();
      if (!x_vector.empty() && !y_vector.empty()) {
        QVector<double> q_x_vector(x_vector.begin(), x_vector.end());
        QVector<double> q_y_vector(y_vector.begin(), y_vector.end());
        ui_->widget_graph->graph()->setData(q_x_vector, q_y_vector);
      }

      ui_->widget_graph->graph()->setPen(QPen(Qt::blue));
      ui_->widget_graph->graph()->setLineStyle(QCPGraph::lsNone);
      QCPScatterStyle myScatter;
      myScatter.setShape(QCPScatterStyle::ssDisc);
      myScatter.setSize(1);
      ui_->widget_graph->graph()->setScatterStyle(myScatter);

      ui_->widget_graph->replot();
    } catch (...) {
      return;
    }
  }
}
