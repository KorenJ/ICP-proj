/**
 * @file MazeObject.hpp
 * @author Jakub Kořínek <xkorin17@stud.fit.vutbr>
 * @brief Hlavičkový soubor pro definici třídy MazeObject reprezentující libovolnou postavu hry.
 */

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
    int lives;
    bool ownsKey;
    int startRow;
    int startCol;

public:
    int steps = 0;
    bool isEnd = false;
    MazeObject(int row, int col, Maze *maze);
    /**
         * @brief Funkce zjistí, jestli je objekt Pacman.
         *
         * @return Vrací true, pokud je objekt pacman, jinak false.
         */
    bool isPacman();
    /**
         * @brief Funkce zjistí, jestli je objekt ghost.
         *
         * @return Vrací true, pokud je objekt ghost, jinak false.
         */
    bool isGhost();
    /**
         * @brief Funkce zjistí, jestli je objekt klíč.
         *
         * @return Vrací true, pokud je objekt klíč, jinak false.
         */
    bool isKey();
    /**
         * @brief Funkce zjistí, jestli je objekt cíl.
         *
         * @return Vrací true, pokud je objekt cíl, jinak false.
         */
    bool isTarget();
    /**
         * @brief Nastaví objekt jako pacmana.
         *
         */
    void setPacman();
    /**
         * @brief Nastaví objekt jako ducha.
         *
         */
    void setGhost();
    /**
         * @brief Nastaví objekt jako klíč.
         *
         */
    void setKey();
    /**
         * @brief Nastaví objekt jako cíl.
         *
         */
    void setTarget();
    /**
         * @brief Funkce zjistí, jestli se může objekt pohnout daným směrem dir. Je třeba zadávat jako Direction::<směr>.
         *
         * @param dir Směr žádaného pohybu.
         * @return Vrátí true, pokud se objekt může posunout daným směrem. Jinak false.
         */
    bool canMove(Direction dir);
    /**
         * @brief Funkce zkopíruje adresu své vlastní instance na sousední políčko ve směru dir a smaže odkaz na původním.
         *
         * @param dir Směr žádaného pohybu.
         * @return Vrátí true po úspěšném přesunu. Jakýkoliv jiný případ vrátí false.
         */
    bool move(Direction dir);
    /**
         * @brief Ubere objektu (Musí být kontrola na Pacmana) jeden život.
         *
         */
    void damage();
    /**
         * @brief Vrátí počet životů objektu (musí být kontrola na Pacmana).
         *
         */
    int get_lives();

    /**
         * @brief Funkce zkontroluje vlastnictví klíče.
         *
         * @return Vráci true, pokud má objekt (Pacman) klíč. Jinak false.
         */
    bool hasKey();

    int getRows();

    int getCols();

    int get_steps();
};

#endif
