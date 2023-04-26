#ifndef FIELD_H
#define FIELD_H

class Field;
enum class Direction{
    D,
    L,
    R,
    U,
};

#include "MazeObject.hpp"
#include "Maze.hpp"

class Field{
    protected:
        int row;
        int col;
        Maze *maze;
        bool move;

        MazeObject *pacman;
        MazeObject *ghost;
        MazeObject *key;
        MazeObject *target;

    public:
        Field(int row, int col, Maze *maze);
        void setPath();
        bool canMove();
        bool isEmpty();
        bool put(MazeObject *object);
        bool remove(MazeObject *object);
        MazeObject* get();
        Field nextField(Direction dir);
};

#endif