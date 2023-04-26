#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <cstring>
#include <iostream>
#include "../headers/Field.hpp"

class Maze{
    protected:
        Field ***field;
        int rows;
        int cols;
        int current_row;

    public:
        bool startReading(int rows, int cols);
        bool processLine(std::string line);
        bool stopReading();
        Maze createMaze();
        void clearMaze();

        Field getField(int row, int col);
};

#endif