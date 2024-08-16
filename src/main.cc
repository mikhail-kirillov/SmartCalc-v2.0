// Copyright 2024 Burr Etienne
#include <QApplication>

#include "view/window.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::MainWindow w;
  w.show();
  return a.exec();
}
