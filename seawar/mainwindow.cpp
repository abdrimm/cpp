#include "mainwindow.h"
#include <iostream>
#include <ctime>
#include <QString>
using namespace std;
MainWindow::MainWindow(QWidget * parent) :
            QMainWindow(parent) {
    setFixedSize(sizeHint());
    setWindowFlags(Qt::FramelessWindowHint);
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    layout = new QGridLayout(centralWidget);
    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);
    int size = 9;
    fields.resize(size);
    for(int i = 0; i < size; ++i) {
        fields[i].resize(size);
        for (int j = 0; j < size ; ++j) {
            Field *newfield = new Field(i, j , this);
            newfield->setText(" ");
            newfield->setFixedSize(60, 60);
            fields[i][j] = newfield;
            layout->addWidget(newfield, i, j);
            connect(newfield, SIGNAL (moved(int, int)),
            this, SLOT(movehandler(int, int)));
        }
    }
    bombGenerator(10);

}
MainWindow::~MainWindow() {
    for(int i = 0; i < fields.size(); ++i) {
        for(int j = 0; j < fields.size(); ++j) {
            delete fields[i][j];
        }
        fields[i].clear();
    }
    fields.clear();
    delete layout;
    delete centralWidget;
}

void MainWindow::movehandler(int row, int col) {
    QString s = QChar(0x2735);
    if(fields[row][col]->getValue() == 1) {
        for(int i = 0; i < 9; ++i ) {
            for(int j = 0; j < 9; ++j) {
                if(fields[i][j]->getValue() == 1) {
                    fields[i][j]->setText(s);
                    fields[i][j]->setEnabled(false);
                } else {
                    fields[i][j]->setEnabled(false);
                }
            }
        }
    } else {
        countBombs(row, col);
    }
    qDebug() << row << col;
}

void  MainWindow::bombGenerator(int numberOfBombs) {
    int row = 0;
    int col = 0;
    srand(time(0));
    for(int i = 0; i < numberOfBombs; ++i) {
        row = 0 + rand() % 9;
        col = 0 + rand() % 9;
        if(fields[row][col]->getValue() == 1) {
            i--;
        }
        else {
            fields[row][col]->setValue(1);
        }
    }
}

void MainWindow::countBombs(int row, int col) {
    int bombCounter = 0;
    for(int i = -1; i <= 1; ++i) {
        for(int j = -1; j <= 1; ++j) {
            if((row + i >= 0 && row + i <= 8) && (col + j >= 0 && col + j <= 8)) {
                if(fields[row + i][col + j]->getValue() == 1) {
                    bombCounter++;
                }
            }
        }
    }
    fields[row][col]->setEnabled(false);
    if(bombCounter == 0) {
        for(int i = -1; i <= 1; ++i) {
            for(int j = -1; j <= 1; ++j) {
                if((row + i >= 0 && row + i <= 8) && (col + j >= 0 && col + j <= 8)) {
                    if((fields[row + i][col + j]->isEnabled() == 1)) {
                        countBombs(row + i, col + j);
                    }
                }
            }
        }
    }  else {
        QString str = QString::number(bombCounter);
        fields[row][col]->setText(str);
    }
}