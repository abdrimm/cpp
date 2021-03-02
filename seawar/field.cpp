#include "field.h"
#include <QDebug>
#include <cstdlib>
Field::Field(int row , int col , QWidget * parent)
    :QPushButton(parent) , row(row), col(col), value(0) {
    qDebug() << " CONSTRUCTOR " ;
    connect(this, SIGNAL ( clicked ()),
    this, SLOT (clickhandler()));
}

void Field::clickhandler() {
    emit moved(row, col);
}
void Field::setValue(int value) {
    this->value = value;
}

int Field::getValue() {
    return value;
}