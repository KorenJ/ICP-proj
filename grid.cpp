 
#include "grid.h"
#include <QPainter>

Grid::Grid(Maze * maze, QGraphicsItem *parent) : QGraphicsItem(parent), m_cellSize(50)
{
    mazeGrid = maze;
}

QRectF Grid::boundingRect() const
{
    return QRectF(0, 0, m_cellSize * 10, m_cellSize * 10);
}

void Grid::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::red);

    MazeObject * tmp;
    bool wall = true;
    for (int x = 0; x <= 10; ++x) {
        for (int y = 0; y <= 10; ++y) {
            wall = mazeGrid->getField(y, x)->canMove();
            tmp = mazeGrid->getField(y, x)->get();
            if(!wall && tmp == NULL){
                wall = true;
                QRectF cellRect((x-1) * m_cellSize, (y-1) * m_cellSize, m_cellSize, m_cellSize);
                painter->setBrush(Qt::red);
                painter->drawRect(cellRect);
            }
            else if(tmp == NULL){
                QRectF cellRect((x-1) * m_cellSize, (y-1) * m_cellSize, m_cellSize, m_cellSize);
                painter->setBrush(Qt::NoBrush);
                painter->drawRect(cellRect);
            }
            else if(tmp->isGhost()){
                QRectF cellRect((x-1) * m_cellSize, (y-1) * m_cellSize, m_cellSize, m_cellSize);
                painter->setBrush(Qt::green);
                painter->drawRect(cellRect);
            }
            else if(tmp->isKey()){
                QRectF cellRect((x-1) * m_cellSize, (y-1) * m_cellSize, m_cellSize, m_cellSize);
                painter->setBrush(Qt::blue);
                painter->drawRect(cellRect);
            }
        }
    }
}
