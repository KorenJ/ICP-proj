 
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <iostream>
#include <fstream>
#include "grid.h"
#include "pacman.h"
#include "headers/Maze.hpp"
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 500, 500);

    //opening new maze, we can add a switch that picks specific maze depending on the players choice
    std::ifstream file;
    Maze *mazeFile = new Maze();
    file.open("save/map.txt");
    qDebug() << "Error opening file: " << file.rdstate();
    int rows;
    int cols;

    if (file.is_open()){
        std::string str_rows;
        file >> str_rows;
        rows = stoi(str_rows);
        std::string str_cols;
        file >> str_cols;
        cols = stoi(str_cols);

        std::string inputstring;

        mazeFile->startReading(rows, cols);

        while (file.good()){
            file >> inputstring;
            if (int(inputstring.length()) != cols){
                qDebug() << "wrong input";
                return 1;
            }
            mazeFile->processLine(inputstring);
        }
    }
    else{
        qDebug() << "couldnt read map\n";
        return 1;
    }

    //initializing maze
    mazeFile->stopReading();
    Maze maze = mazeFile->createMaze();

    //getting starting point of pacman
    MazeObject *pacmanTmp = nullptr;
    int flag = 0;
    int setPosR = 0;
    int setPosC = 0;
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            if((pacmanTmp = maze.getField(r,c)->get())){
                if(pacmanTmp->isPacman() == true){
                    flag = 1;
                    setPosR = r;
                    setPosC = c;
                    break;
                }
            }
        }
        if(flag == 1){
            break;
        }
    }

    Grid grid(&maze);
    scene.addItem(&grid);


    Pacman pacman(pacmanTmp, &maze);
    pacman.setPos((setPosC * 50) - 50, (setPosR * 50) - 50);
    scene.addItem(&pacman);

    QGraphicsView view(&scene);
    view.show();

    return a.exec();
}
