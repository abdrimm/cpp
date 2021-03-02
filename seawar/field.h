#ifndef FIELD_H
#define FIELD_H
#include <QPushButton>
#include <QWidget>

 class Field: public QPushButton {
 Q_OBJECT
    int row, col;
    int value;

 public:
    Field(int row, int col, QWidget *parent = NULL);
    void setValue(int value);
    int getValue();
 signals:
    void moved(int row, int col);

 public slots:
    void clickhandler();
 };
#endif