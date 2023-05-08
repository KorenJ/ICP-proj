#ifndef MAINMENU_H
#define MAINMENU_H


#include <QGraphicsItem>
#include <QPainter>
#include <QKeyEvent>
#include <QObject>
#include <headers/MazeObject.hpp>
#include <QTimer>
#include <QGraphicsScene>
#include <QPushButton>
#include <QFile>
#include <iostream>
#include <fstream>
#include <QGraphicsView>
#include "Log.h"
#include <QLabel>
#include <QGraphicsProxyWidget>



class mainMenu :public QObject{
    Q_OBJECT
public:

    bool clickedOnce = false;
    int startGame();
    QGraphicsRectItem *blackRectangle;
    QPushButton *startGameButton;
    QGraphicsScene *mainScene;
    QGraphicsView *mainView;
    QGraphicsScene *gameScene;
    QGraphicsView *gameView;
    QTimer * slotTimer;
    Log * m_log;
    QLabel *livesLabel;
    QLabel *stepsLabel;
    MazeObject *pacmanForLives;

    QGraphicsProxyWidget* proxyWidget;

    int currentLives;
    int previousLives = 3;

    int positionx;
    int positiony;
    bool isPressed = false;

    bool getPressed();

    mainMenu(QGraphicsScene *scene, QTimer *timer, int xPos, int yPos, MazeObject * pacman);
    void startMenu();
public slots:
    void buttonClicked();
    void interactivesUpdate();
private:
    std::ifstream file;
};


#endif
