#ifndef MAZEBUTTON_H
#define MAZEBUTTON_H


#include "qmainwindow.h"
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



class MazeButton :public QObject{
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
    QMainWindow *windowMaze;
    QMainWindow *newWindowMaze;

    int positionx;
    int positiony;
    bool isPressed = false;

    bool getPressed();

    MazeButton(QGraphicsScene *scene, QTimer *timer, int xPos, int yPos, QMainWindow *w, QMainWindow *newWindow);
    void startMenu();
public slots:
    void buttonClicked();
private:
    std::ifstream file;
};


#endif
