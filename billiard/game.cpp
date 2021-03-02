#include <QPainter>
#include <QColor>
#include <QDebug>
#include "game.h"
#include <time.h>
Game::Game() {
  size = QSize(1277, 721);
  srand(time(0));
  position[0] = QVector2D(600, 650);
  position[1] = QVector2D(650, 750);
  velocity[0] = QVector2D(0, 200);
  velocity[1] = QVector2D(200, 0);
  texture_ball = new QPixmap("C:/Qt/billiard2/pictures/ball.png");
  gravity = QVector2D(0.0, 5.0);
  tau = 0.1;
  radius = 50.0;
}

void Game::step() {
    QVector2D vectorDistance;
    double length;
    QVector2D tan[2];
    QVector2D norm[2];
    QVector2D e;
    position[0] = position[0] + tau * velocity[0];
    velocity[0] = velocity[0] + tau * gravity;
    position[1] = position[1] + tau * velocity[1];
    velocity[1] = velocity[1] + tau * gravity;
  QVector2D normal[] = { QVector2D(1, 0),
                         QVector2D(0, -1),
                         QVector2D(-1, 0),
                         QVector2D(0, 1) };
  QVector2D border[] = { QVector2D(radius, radius),
                         QVector2D(radius, size.height() - radius),
                         QVector2D(size.width() - radius, size.height() - radius),
                         QVector2D(size.width() - radius, radius)};
  for (int i = 0; i < 4; i++) {
      for(int j = 0; j < 2; ++j) {
          qreal normal_factor = QVector2D::dotProduct(position[j] - border[i], normal[i]);
          if (normal_factor < 0) {
            position[j] = position[j] - 2 * normal_factor * normal[i];
            velocity[j] = velocity[j] - 2 * QVector2D::dotProduct(velocity[j], normal[i]) * normal[i];
      }

    }
  }
  vectorDistance = position[0] - position[1];
  length = vectorDistance.length();
  if(length <= radius * 2) {
      length = radius * 2 - length;
      e = vectorDistance.normalized();
      position[0] = position[0] + (e * length / 2);
      position[1] = position[1] + (-e * length / 2);
      norm[0] = QVector2D::dotProduct(velocity[0], e) * e ;
      tan[0] = velocity[0] - norm[0];
      norm[1] = QVector2D::dotProduct(velocity[1], e) * e ;
      tan[1] = velocity[1] - normal[1];
      velocity[0] = tan[0] + norm[1];
      velocity[1] = tan[1] + norm[0];
  }
}

void Game::draw(QPixmap *pixmap) {
  pixmap->fill(Qt::white);
  QPainter painter(pixmap);
  for(int i = 0; i < 2; ++i) {
      painter.drawPixmap(position[i].x() - radius,
                         position[i].y() - radius,
                         *texture_ball);
  }
}

Game::~Game() {
    delete texture_ball;
}