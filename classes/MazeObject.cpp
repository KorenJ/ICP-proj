#include "../headers/MazeObject.hpp"

MazeObject::MazeObject(int row, int col, Maze *maze){
    this->row = row;
    this->col = col;
    this->maze = maze;
    this->ghost = false;
    this->pacman = false;
    this->key = false;
    this->target = false;
}

bool MazeObject::isPacman(){
    return this->pacman;
}

bool MazeObject::isGhost(){
    return this->ghost;
}

bool MazeObject::isKey(){
    return this->key;
}

bool MazeObject::isTarget(){
    return this->target;
}

void MazeObject::setPacman(){
    this->pacman = true;
}

void MazeObject::setGhost(){
    this->ghost = true;
}

void MazeObject::setKey(){
    this->key = true;
}

void MazeObject::setTarget(){
    this->target = true;
}

bool MazeObject::canMove(Direction dir){
    switch (dir){
        case Direction::D:
            return (*this->maze).getField(this->row+1, this->col)->canMove();
            break;
        case Direction::L:
            return (*this->maze).getField(this->row, this->col-1)->canMove();
            break;
        case Direction::R:
            return (*this->maze).getField(this->row, this->col+1)->canMove();
            break;
        case Direction::U:
            return (*this->maze).getField(this->row-1, this->col)->canMove();
            break;
        default:
            return false;
    }
}

bool MazeObject::move(Direction dir){
    if (canMove(dir)){
        (*this->maze).getField(this->row,this->col)->nextField(dir)->put(this);
        (*this->maze).getField(this->row,this->col)->remove(this);
        switch (dir){
            case Direction::D:
                this->row++;
                break;
            case Direction::L:
                this->col--;
                break;
            case Direction::R:
                this->col++;
                break;
            case Direction::U:
                this->row--;
                break;
        }
        return true;
    }
    return false;
}