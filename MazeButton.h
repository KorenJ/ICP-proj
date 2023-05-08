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
#include "Log.h"



class MazeButton :public QObject{
    Q_OBJECT
public:

    int startGame();
    QGraphicsRectItem *blackRectangle;
    QPushButton *logForwardButton;
    QPushButton *logBackwardsButton;
    QGraphicsScene *mainScene;
    QGraphicsView *mainView;
    QGraphicsScene *logScene;
    QGraphicsView *gameView;
    QTimer * slotTimer;
    QMainWindow *windowMaze;
    QMainWindow *windowLog;

    QTimer m_timer;

    Log *m_log;

    bool forwardLog = true;

    int positionx;
    int positiony;
    bool isPressed = false;

    bool getPressed();


    MazeButton(QGraphicsScene *scene, QGraphicsScene * logScene, int xPos, int yPos, QMainWindow *w, QMainWindow *newWindow, Log *log);
    void startMenu();
public slots:
    void buttonClicked();
    void backwardsButtonClicked();
    void playLog();
private:
    std::ifstream file;
};


#endif
