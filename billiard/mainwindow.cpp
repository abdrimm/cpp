#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
            QMainWindow(parent) {
  resize(500, 500);
  centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);
  layout = new QGridLayout(centralWidget);
  label = new QLabel(this);
  layout->addWidget(label, 0, 0);
  pixmap = new QPixmap("C:/Qt/billiard2/pictures/table.png");
  frame();
  timerid = startTimer(40);
}

MainWindow::~MainWindow() {
  delete pixmap;
  delete label;
  delete layout;
  delete centralWidget;
}

void MainWindow::timerEvent(QTimerEvent *event) {
  frame();
}

void MainWindow::frame() {
  game.step();
  game.draw(pixmap);
  label->setPixmap(*pixmap);
}