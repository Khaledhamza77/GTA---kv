#ifndef POWERUP_H
#define POWERUP_H

#include <QGraphicsPixmapItem>
#include <QProgressBar>
class Powerup : public QGraphicsPixmapItem
{
public:
    Powerup();
    int duration;
    QProgressBar timer;
};

#endif // POWERUP_H
