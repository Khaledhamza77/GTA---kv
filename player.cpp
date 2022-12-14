#include "player.h"


Player::Player(int boardData[12][12])
{
    // Set Image
    QPixmap image("C:/Users/NEW LAP/Desktop/CS2 Work/Class-Project-main/Class-Project-main/projectresourse - Copy/nerddefault.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);

    // Set Position
    row = 4;
    column = 5;
    setPos(50 + column * 50, 50 + row * 50);

    // Set data Array
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            data[i][j] = boardData[i][j];


//set music theme
//    music->setSource(QUrl::fromLocalFile("C:/Users/wifi/Downloads/Mission Impossible Theme (Full Theme).mp3"));
//    musicaudio->setVolume(5);
//    music->setAudioOutput(musicaudio);
//    music->play();

}
void Player::keyPressEvent(QKeyEvent* event)
{  //QMediaPlayer *player = new QMediaPlayer;
//     QAudioOutput *audioOutput = new QAudioOutput;
    if (event->key() == Qt::Key_Up && data[row - 1][column] >= 0)
    {

// audio queue for movement

//        player->setAudioOutput(audioOutput);
//        player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/wet-metal-footsteps-32703 (mp3cut.net)(1).mp3"));
//        audioOutput->setVolume(50);
//        player->play();
//move the player
        row--;

    }
    else if (event->key() == Qt::Key_Down && data[row + 1][column] >= 0)
    {
//        player->setAudioOutput(audioOutput);
//        player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/wet-metal-footsteps-32703 (mp3cut.net)(2).mp3"));
//        audioOutput->setVolume(50);
//        player->play();
        row++;
    }
    else if (event->key() == Qt::Key_Right && data[row][column + 1] >= 0)
    { // changing character model when moving to right
        QPixmap image("C:/Users/NEW LAP/Desktop/CS2 Work/Class-Project-main/Class-Project-main/projectresourse - Copy/nerddefault.png");
        image = image.scaledToWidth(50);
        image = image.scaledToHeight(50);
        QTransform tr;
            tr.scale(1, 1);
          image= image.transformed(tr);
           setPixmap(image);
           //player->setAudioOutput(audioOutput);
           //player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/wet-metal-footsteps-32703 (mp3cut.net).mp3"));
           //audioOutput->setVolume(50);
           //player->play();
        column++;
    }
    else if (event->key() == Qt::Key_Left && data[row][column - 1] >= 0)
    { // changing character model when moving to left
        QPixmap image("C:/Users/NEW LAP/Desktop/CS2 Work/Class-Project-main/Class-Project-main/projectresourse - Copy/nerddefault.png");
        image = image.scaledToWidth(50);
        image = image.scaledToHeight(50);
        QTransform tr;
            tr.scale(-1, 1);
          image= image.transformed(tr);
           setPixmap(image);
           //player->setAudioOutput(audioOutput);
           //player->setSource(QUrl::fromLocalFile("C:/Users/wifi/OneDrive/Documents/projectresourse/sound/wet-metal-footsteps-32703 (mp3cut.net).mp3"));
           //audioOutput->setVolume(50);
           //player->play();
        column--;
    }
    setPos(50 + column * 50, 50 + row * 50);

    QList<QGraphicsItem*> items = collidingItems();
        for (int i = 0; i < items.size(); i++)
        {
            if (typeid(*items[i]) == typeid(Powerup))
                scene()->removeItem(items[i]);

        }
     QList<QGraphicsItem*> bullets = collidingItems();
            for (int i = 0; i < bullets.size(); i++)
            {
                if (typeid(*bullets[i]) == typeid(Bullet))
                    scene()->removeItem(bullets[i]);

            }
    QList<QGraphicsItem*> Powerups = collidingItems();
            for (int i = 0; i < Powerups.size(); i++)
            {
                if (typeid(*Powerups[i]) == typeid(Powerup))
                    scene()->removeItem(Powerups[i]);
            }
    }

