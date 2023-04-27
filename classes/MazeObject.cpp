#include "../headers/MazeObject.hpp"

MazeObject::MazeObject(int row, int col, Maze *maze){
    this->row = row;
    this->col = col;
    this->maze = maze;
    this->ghost = false;
    this->pacman = false;
    this->key = false;
    this->target = false;
    this->lives = 3;
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
        Field *nextField = (*this->maze).getField(this->row, this->col)->nextField(dir);
        Field *thisField = (*this->maze).getField(this->row,this->col);
        // tento blok se spustí jen pokud je v cílovém poli nějaký objekt
        if (!nextField->isEmpty()){
            MazeObject *nextObject = nextField->get();
            // tento objekt je Pacman a v cíli je Ghost -> uber život a přesuň
            if (this->isPacman()){
                if (nextObject->isGhost())
                    this->damage();
            }
            // tento objekt je duch ...
            else if (this->isGhost()){
                //... a v cíli je Pacman -> uber život a přesuň
                if (nextObject->isPacman())
                    nextObject->damage();
                //... a v cíli je další duch -> zůstaň stát
                else if (nextObject->isGhost())
                    return false;
            }
        }
        nextField->put(this);
        thisField->remove(this);
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

void MazeObject::damage(){
    this->lives--;
}

int MazeObject::get_lives(){
    return this->lives;
}