#include "powerup.h"

Powerup::Powerup()
    {
        // Set Image
        QPixmap image("C:/Users/NEW LAP/Desktop/CS2 Work/Class-Project-main/Class-Project-main/pngegg (4).png");
        image = image.scaledToWidth(50);
        image = image.scaledToHeight(50);
        setPixmap(image);
        duration = 5;
        timer.setOrientation(Qt::Horizontal);
        timer.setRange(0, 50);
        timer.setValue(duration);
        // Set Position
        setPos(50 + 5 * 50, 50 + 5 * 50);
    }
