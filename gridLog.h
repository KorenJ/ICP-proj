#ifndef GRIDLOG_H
#define GRIDLOG_H

#include <iostream>
#include <fstream>
#include <QGraphicsItem>
#include <headers/MazeObject.hpp>

class GridLog : public QGraphicsItem
{
public:
    GridLog(Maze *maze, QGraphicsItem *parent = nullptr);
    Maze *mazeGrid;
    int rows;
    int cols;
    int logfilesCount;
    std::ifstream file;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    int readMaze();


private:
    int m_cellSize;
};

#endif // GRIDLOG_H
