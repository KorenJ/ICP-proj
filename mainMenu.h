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



class mainMenu :public QObject{
    Q_OBJECT
public:

    int startGame();
    QGraphicsRectItem *blackRectangle;
    QPushButton *startGameButton;
    QGraphicsScene *mainScene;
    QGraphicsView *mainView;
    QGraphicsScene *gameScene;
    QGraphicsView *gameView;
    QTimer * slotTimer;

    int positionx;
    int positiony;
    bool isPressed = false;

    bool getPressed();

    mainMenu(QGraphicsScene *scene, QTimer *timer, int xPos, int yPos);
    void startMenu();
public slots:
    void buttonClicked();
private:
    std::ifstream file;
};


#endif
