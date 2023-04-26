/**
 * @file Field.cpp
 * @author your name (you@domain.com)
 * @brief Implementace tříd reprezentující konkrétní políčko v bludišti.
 */

#include "../headers/Field.hpp"
#include "../headers/Maze.hpp"

Field::Field(int row, int col, Maze maze){
    this->row = row;
    this->col = col;
    this->maze = maze;
    this->move = false;
}

void Field::setPath(){
    this->move = true;
}

bool Field::canMove(){
    return this->move;
}

bool Field::isEmpty(){
    return false;
}
 
bool Field::put(){
    if (this->canMove()){
        return true;
    }
    return false;
}

bool Field::remove(){
    if (this->canMove()){
        return true;
    }
    return false;
}

MazeObject* Field::get(){
    return nullptr;
}
        
Field* Field::nextField(Field::Direction dir){
    return nullptr;
}