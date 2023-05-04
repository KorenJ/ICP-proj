#include <QTime>
#include <QApplication>
#include <QGraphicsScene>
#include <headers/MazeObject.hpp>
#include <headers/Field.hpp>
#include <QDebug>
#include <QTimer>
#include <QPushButton>
#include <QObject>
#include "grid.h"
#include "pacman.h"
#include "ghost.h"
#include "headers/Maze.hpp"
#include "mainMenu.h"
#include <QDebug>
#include <QPushButton>
#include <QFile>
#include "MazeButton.h"
#include "qmainwindow.h"



MazeButton::MazeButton(QGraphicsScene *scene, QTimer *timer, int xPos, int yPos, QMainWindow *win, QMainWindow *newWindow)
{
    startGameButton = new QPushButton("Maze2");
    mainScene = scene;
    connect(startGameButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    slotTimer = timer;
    positionx = xPos;
    positiony = yPos;
    windowMaze = win;

}

void MazeButton::startMenu(){

    startGameButton->setGeometry(positionx, positiony, 150, 50);
    mainScene->addWidget(startGameButton);
}

void MazeButton::buttonClicked(){
    windowMaze->close();
}

bool MazeButton::getPressed(){
    return isPressed;
}
