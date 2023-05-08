/**
 * @file Field.hpp
 * @author Jakub Kořínek <xkorin17@stud.fit.vutbr.cz>
 * @brief Hlavičkový soubor definující třídy Field a Direction. Field reprezentuje pole bludiště a Direction směry.
 *
 */

#ifndef FIELD_H
#define FIELD_H

class Field;
enum class Direction{
    D,
    L,
    R,
    U,
    None
};

#include "MazeObject.hpp"
#include "Maze.hpp"

class Field{
protected:
    int row;
    int col;
    Maze *maze;


public:
    bool move;
    MazeObject *pacman;
    MazeObject *ghost;
    MazeObject *key;
    MazeObject *target;

    Field(int row, int col, Maze *maze);
    /**
         * @brief Nastaví toto políčko jako cestu, po které se dá jít. (tedy ne zeď)
         *
         */
    void setPath();
    /**
         * @brief Funkce rozlišuje zeď od cesty.
         *
         * @return Vrátí true, pokud se jedná o cestu. V případě zdi vrací False.
         */
    bool canMove();
    /**
         * @brief Funkce zjistí, jestli je políčko prázdné.
         *
         * @return Vrátí true, pokud políčko neobsahuje žádný objekt třídy MazeObject. Jinak false.
         */
    bool isEmpty();
    /**
         * @brief Funkce umístí požadovaný objekt na políčko.
         *
         * @param object Instance třídy MazeObject.
         * @return Vrátí true po úspěšném zapsání adresy objektu do políčka. Jakýkoliv jiný případ je false.
         */
    bool put(MazeObject *object);
    /**
         * @brief Odstraní požadovaný objekt z políčka.
         *
         * @param object Instance třídy MazeObject.
         * @return Vrátí true, pokud na původním políčku již neexistuje adresa dané instance. Jinak false.
         */
    bool remove(MazeObject *object);
    /**
         * @brief Funkce získá objekt na políčku. Hledá je postupně v tomto pořadí: 1) Pacman 2) Duch 3) Klíč 4) Cíl.
         *
         * @return Vrací adresu prvního získaného objektu. Pokud je pole prázdné, vrací nullptr(!).
         */
    MazeObject* get();
    /**
         * @brief Funkce vrátí adresu sousedního políčka.
         *
         * @param dir Směr požadovaného souseda.
         * @return Vrátí adresu sousedního pole.
         */
    Field* nextField(Direction dir);

    bool getGhost();

};

#endif
