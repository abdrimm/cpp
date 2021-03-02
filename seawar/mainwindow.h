#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QVector>
#include "field.h"
#include <QDebug>

class MainWindow: public QMainWindow {
    Q_OBJECT
    QWidget *centralWidget ;
    QGridLayout *layout ;
    QVector <QVector<Field*>> fields;
public :
    MainWindow(QWidget *parent = NULL);
    ~MainWindow();
    void bombGenerator(int numberOfBombs);
    void countBombs(int row, int col);
public slots:
    void movehandler(int row, int col);
};
#endif