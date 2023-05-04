/**
 * @file Maze.hpp
 * @author Jakub Kořínek <xkorin17@stud.fit.vutbr.cz>
 * @brief Hlavičkový soubor pro definici třídy reprezentující celé bludiště.
 */

#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <cstring>
#include <iostream>
#include "Field.hpp"

class Maze{
protected:
    /**
         * @brief Samotné bludiště je uloženo jako matice pointerů, na které se naváží konkrétní instance políček.
         *
         */
    Field ***field;
    int rows;
    int cols;
    int current_row;

public:
    /**
         * @brief Funkce alokuje potřebnou pamět pro zadané rozměry a naplní první řádek zdmi.
         *
         * @param rows Požadovaný počet řádků.
         * @param cols Požadovaný počet sloupců.
         * @return Vrací true při úspěchu, jinak false.
         */
    bool startReading(int rows, int cols);
    /**
         * @brief Funkce zpracuje celý řádek.
         *
         * @param line Řádek reprezentovaný stringem.
         * @return Vrací true při úspěchu, jinak false.
         */
    bool processLine(std::string line);
    /**
         * @brief Funkce ukončí načítání mapy a naplní poslední řádek zdmi.
         *
         * @return Vrací true při úspěchu, jinak false.
         */
    bool stopReading();
    /**
         * @brief Funkce vrátí sama sebe jako načtenou mapu.
         *
         * @return Instance třídy bludiště.
         */
    Maze createMaze();
    /**
         * @brief Uklidí alokovanou pamět.
         *
         */
    void clearMaze();
    /**
         * @brief Funkce načítá konkrétní pole ze souřadnic.
         *
         * @param row Pozice x políčka.
         * @param col Pozice y políčka.
         * @return Vrátí instanci třídy políčko.
         */
    int getRows(){
        return this->rows;
    }
    int getCols(){
        return this->cols;
    }
    Field* getField(int row, int col);
};

#endif
