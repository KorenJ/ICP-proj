#include <iostream>
#include <fstream>

#include "../headers/Field.hpp"
#include "../headers/MazeObject.hpp"
#include "../headers/Maze.hpp"

int main(){

    std::ifstream file;
    file.open("../save/map.txt");
    Maze *m = new Maze();

    if (file.is_open()){
        std::string str_rows;
        file >> str_rows;
        int rows;
        rows = stoi(str_rows);
        std::string str_cols;
        file >> str_cols;
        int cols;
        cols = stoi(str_cols);

        std::string inputstring;

        m->startReading(rows, cols);

        while (file.good()){
            file >> inputstring;
            if (inputstring.length() != cols){
                std::cerr << "Nesprávný vstup.\n";
                return 1;
            }
            m->processLine(inputstring);
        }
    }
    else{
        std::cerr << "Chyba načtení souboru\n";
        return 1;
    }

    m->stopReading();
    Maze maze = m->createMaze();

    Field f = maze.getField(1,1);
    if (f.canMove() && f.isEmpty())
        std::cout << "SUCCESS1\n";
    f = maze.getField(0,0);
    if (!f.canMove())
        std::cout << "SUCCESS2\n";
    
    //key
    f = maze.getField(1,10);
    if (!f.isEmpty() && f.canMove())
        std::cout << "SUCCESS3\n";

    //pacman
    f = maze.getField(9,1);
    if (!f.isEmpty() && f.canMove())
        std::cout << "SUCCESS4.1\n";
    MazeObject *pacman = f.get();
    if (pacman->isPacman())
        std::cout << "SUCCESS4.2\n";
    f = f.nextField(Direction::R);
    if (f.isEmpty())
        std::cout << "SUCCESS4.3 - TARGET FIELD IS EMPTY\n";
    if (pacman->move(Direction::R))
        std::cout << "SUCCESS4.4 - MOVING\n";
    if (!f.isEmpty())
        std::cout << "SUCCESS4.5 - TARGET FIELD IS NOT EMPTY\n";
    Field fOG = maze.getField(9,1);
    if (fOG.isEmpty())
        std::cout << "SUCCESS4.6 - ORIGINAL FIELD EMPTY\n";
    if (!pacman->move(Direction::U))
        std::cout << "SUCCESS4.7 - MOVING INTO WALL\n";
    if (!f.isEmpty())
        std::cout << "SUCCESS4.8 - PACMAN DIDN'T MOVE\n";

    maze.clearMaze();
    file.close();

    return 0;
}