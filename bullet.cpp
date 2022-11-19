#include "bullet.h"

Bullet::Bullet()
{
    QPixmap image("C:/Users/NEW LAP/Desktop/CS2 Work/Class-Project-main/Class-Project-main/projectresourse - Copy/bullet.png");
    image = image.scaledToWidth(30);
    image = image.scaledToHeight(30);
    setPixmap(image);

    // Set Position
    setPos(50 + 1 * 50, 50 + 1 * 50);
}
