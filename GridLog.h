#ifndef GRID_H
#define GRID_H

#include <QGraphicsItem>
#include <headers/MazeObject.hpp>

class GridLog : public QGraphicsItem
{
public:
    GridLog(Maze *maze, QGraphicsItem *parent = nullptr);
    Maze *mazeGrid;
    int rows;
    int cols;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


private:
    int m_cellSize;
};

#endif // GRID_H
