#ifndef FIELD_H
#define FIELD_H

class Field;

#include "MazeObject.hpp"
#include "Maze.hpp"

class Field{
    protected:
        int row;
        int col;
        Maze maze;
        bool move;
    public:
        enum Direction{
            D,
            L,
            R,
            U,
        };

        Field(int row, int col, Maze mate);
        void setPath();
        bool canMove();
        bool isEmpty();
        bool put();
        bool remove();
        MazeObject* get();
        Field* nextField(Field::Direction dir);
};

#endif