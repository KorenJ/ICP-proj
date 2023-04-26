/**
 * @file Maze.cpp
 * @author Jakub Kořínek <xkorin17@stud.fit.vutbr.cz>
 * @brief Implementace třídy Maze reprezentující bludiště.
 */

#include "../headers/MazeObject.hpp"
#include "../headers/Field.hpp"
#include "../headers/Maze.hpp"

        bool Maze::startReading(int rows, int cols){
            this->rows = rows+2;
            this->cols = cols+2;
            this->current_row = 1;

            this->field = new Field**[this->rows];
            for (int i = 0; i < this->rows; ++i)
                this->field[i] = new Field*[this->cols];

            for (int i = 0; i < this->cols; i++){
                this->field[0][i] = new Field(0, i, *this);
            }

            return true;            
        }

        bool Maze::processLine(std::string line){
            const int lenght = line.length();
            if (lenght != this->cols-2){
                return false;
            }
            char *parsed_line = new char[lenght+1];
            strcpy(parsed_line, line.c_str());

            this->field[this->current_row][0] = new Field(this->current_row, 0, *this);
            this->field[this->current_row][0]->setPath();

            for (int i = 1; i < lenght+1; i++){
                switch(parsed_line[i-1]){
                    case '.':
                        this->field[this->current_row][i] = new Field(this->current_row, i, *this);
                        this->field[this->current_row][i]->setPath();
                        break;
                    case 'X':
                        this->field[this->current_row][i] = new Field(this->current_row, i, *this);
                        break;
                    default:
                        break;
                }
            }

            this->field[this->current_row][this->cols-1] = new Field(this->current_row, 0, *this);

            this->current_row++;

            return true;

        }

        bool Maze::stopReading(){
            for (int i = 0; i < this->cols; i++){
                this->field[this->rows-1][i] = new Field(this->rows-1, i, *this);
            }
            return true;
        }

        Maze Maze::createMaze(){
            return *this;
        }

        void Maze::clearMaze(){
            for (int i = 0; i < this->rows; ++i){
                for (int j = 0; j < this->cols; ++j){
                    delete [] this->field[i][j];
                }
                delete [] this->field[i];
            }
            delete [] this->field;                
        }

        Field Maze::getField(int row, int col){
            return *this->field[row][col];
        }