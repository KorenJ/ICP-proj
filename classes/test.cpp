#include <iostream>
#include <fstream>

#include "../headers/Field.hpp"
#include "../headers/MazeObject.hpp"
#include "../headers/Maze.hpp"

int main(){

    std::ifstream file;
    file.open("../save/map.txt");
    Maze *m = new Maze();
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

        m->startReading(rows, cols);

        while (file.good()){
            file >> inputstring;
            if (inputstring.length() != cols){
                std::cerr << "Nesprávný vstup.\n";
                return 1;
            }
            m->processLine(inputstring);
        }
        
        m->stopReading();
    }
    else{
        std::cerr << "Chyba načtení souboru\n";
        return 1;
    }

    Maze maze = m->createMaze();

    Field *f = maze.getField(1,1);
    if (f->canMove() && f->isEmpty())
        std::cout << "SUCCESS 1\n";
    f = maze.getField(0,0);
    if (!f->canMove())
        std::cout << "SUCCESS 2\n";
    
    //key
    f = maze.getField(1,10);
    if (!f->isEmpty() && f->canMove())
        std::cout << "SUCCESS 3\n";

    //pacman
    f = maze.getField(9,1);
    if (!f->isEmpty())
        std::cout << "SUCCESS 4.1 - OBJECT EXISTS\n";
    MazeObject *pacman = f->get();
    if (pacman->isPacman())
        std::cout << "SUCCESS 4.2 - OBJECT IS PACMAN\n";
    f = maze.getField(9,2);
    if (f->isEmpty() && f->canMove())
        std::cout << "SUCCESS 4.3 - TARGET FIELD IS EMPTY\n";
    if (pacman->move(Direction::R))
        std::cout << "SUCCESS 4.4 - MOVING\n";
    if (!f->isEmpty())
        std::cout << "SUCCESS 4.5 - TARGET FIELD IS NOT EMPTY\n";
    else
        std::cout << "FAIL 4.5 - TARGET FIELD IS EMPTY\n";
    Field *fOG = maze.getField(9,1);
    if (fOG->isEmpty())
        std::cout << "SUCCESS 4.6 - ORIGINAL FIELD EMPTY\n";
    if (!pacman->move(Direction::U))
        std::cout << "SUCCESS 4.7 - MOVING INTO WALL\n";
    if (!f->isEmpty())
        std::cout << "SUCCESS 4.8 - PACMAN DIDN'T MOVE\n";

    //duch a srážka
    Field *ghostF = maze.getField(9,5);
    MazeObject *ghost = ghostF->get();
    if (ghost->isGhost())
        std::cout << "SUCCESS 5.1 - OBJECT IS A GHOST\n";
    if (ghost->move(Direction::L))
        std::cout << "SUCCESS 5.2.1 - MOVING GHOST LEFT\n";
    if (ghost->move(Direction::L))
        std::cout << "SUCCESS 5.2.2 - MOVING GHOST LEFT\n";
    ghostF = maze.getField(9,3);
    if (!ghostF->isEmpty() && !f->isEmpty())
        std::cout << "SUCCESS 5.3 - GHOST ON [9,3] (PACMAN ON [9,2])\n";
    if (pacman->get_lives() == 3)
        std::cout << "SUCCESS 5.4 - PACMAN STILL HAS 3 LIVES\n";
    if (ghost->move(Direction::L))
        std::cout << "SUCCESS 5.5 - MOVING GHOST LEFT TO PACMAN'S POSITION\n";
    if (pacman->get_lives() == 2)
        std::cout << "SUCCESS 5.6 - PACMAN IS DAMAGED\n";
    if (ghost->move(Direction::L))
        std::cout << "SUCCESS 5.7 - MOVING GHOST LEFT FROM PACMAN'S POSITION\n";
    ghostF = maze.getField(9,1);
    if (ghostF->get()->isGhost())
        std::cout << "SUCCESS 5.8 - GHOST MOVED\n";
    if (f->get()->isPacman())
        std::cout << "SUCCESS 5.9 - PACMAN STAYED\n";

    //mechanika klíče a brány
    Field *pacmanField = maze.getField(9,9);
    pacman = pacmanField->get();
    Field *targetField = maze.getField(7,9);
    Field *keyField = maze.getField(8,9);
    if (targetField->get()->isTarget())
        std::cout << "SUCCESS 6.1 - OBJECT IS TARGET\n";
    if (keyField->get()->isKey())
        std::cout << "SUCCESS 6.2 - OBJECT IS KEY\n";
    if (pacman->move(Direction::U))
        std::cout << "SUCCESS 6.3 - MOVING PACMAN UP\n";
    if (keyField->get()->isPacman() && pacman->hasKey())
        std::cout << "SUCCESS 6.4 - KEY TAKEN BY PACMAN\n";
    pacman->move(Direction::L);
    if (keyField->isEmpty())
        std::cout << "SUCCESS 6.5 - KEY NO LONGER EXISTS\n";
    pacman->move(Direction::R);
        std::cout << "FOLLOWING MESSAGE SHOULD BE 'KONEC HRY':\n";
    pacman->move(Direction::U);
    pacmanField = maze.getField(6,9);
    pacman = pacmanField->get();
    if (!pacman->hasKey() && !pacman->move(Direction::D));
        std::cout << "SUCCESS 6.6 - PACMAN DIDN'T MOVE TO TARGET WITHOUT A KEY\n";

    //uklid
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= cols; j++){
            Field *tmp = maze.getField(i,j);
            if (!tmp->isEmpty()){
                MazeObject *object = tmp->get();
                tmp->remove(object);
                delete object;
            }
        }
    }
    maze.clearMaze();
    delete m;
    file.close();

    return 0;
}