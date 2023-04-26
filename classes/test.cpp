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
    if (f.canMove())
        std::cout << "SUCCESS\n";
    Field f1 = maze.getField(0,0);
    if (!f1.canMove())
        std::cout << "SUCCESS\n";

    maze.clearMaze();
    file.close();

    return 0;
}