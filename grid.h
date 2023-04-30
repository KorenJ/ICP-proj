 
#ifndef GRID_H
#define GRID_H

#include <QGraphicsItem>
#include <headers/MazeObject.hpp>

class Grid : public QGraphicsItem
{
public:
    Grid(Maze *maze, QGraphicsItem *parent = nullptr);
    Maze *mazeGrid;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int m_cellSize;
};

#endif // GRID_H
