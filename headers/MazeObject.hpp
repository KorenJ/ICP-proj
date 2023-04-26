#ifndef MAZEOBJECT_H
#define MAZEOBJECT_H

class MazeObject;

#include "Field.hpp"
#include "Maze.hpp"

class MazeObject{
    private:
        int row;
        int col;
        Maze *maze;
        bool ghost;
        bool pacman;
        bool key;
        bool target;

    public:
        MazeObject(int row, int col, Maze *maze);
        bool isPacman();
        bool isGhost();
        bool isKey();
        bool isTarget();
        void setPacman();
        void setGhost();
        void setKey();
        void setTarget();
        bool canMove(Direction dir);
        bool move(Direction dir);
};

#endif