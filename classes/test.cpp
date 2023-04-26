#include <iostream>

#include "../headers/Field.hpp"
#include "../headers/MazeObject.hpp"
#include "../headers/Maze.hpp"

int main(){

    std::cout << "Haha" << "\n";

    Maze *m = new Maze();
    m->startReading(2,2);
    m->processLine("X.");
    m->processLine("..");
    m->stopReading();
    Maze maze = m->createMaze();

    Field f = maze.getField(1,2);
    if (f.canMove())
        std::cout << "SUCCESS\n";
    Field f1 = maze.getField(1,1);
    if (!f1.canMove())
        std::cout << "SUCCESS\n";

    return 0;
}