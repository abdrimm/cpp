#ifndef _GAME_H
#define _GAME_H
#include <QVector2D>
#include <QSize>
#include <QPixmap>

class Game {
      QSize size;
      QVector2D position[2];
      QVector2D velocity[2];
      QVector2D gravity;
      double tau;
      double radius;
      QPixmap *texture_ball;
      QPixmap *table;
      friend class MainWindow;
public:
      Game();
      ~Game();
      void step();
      void draw(QPixmap *pixmap);
};

#endif
