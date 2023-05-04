#ifndef GHOST_H
#define GHOST_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>
#include "headers/MazeObject.hpp"
#include "headers/Maze.hpp"

class Ghost : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Ghost(MazeObject* mazeObject, Maze* maze, QTimer *mainTimer, QObject *parent = nullptr);

public slots:
    void move();

private:
    int rows;
    int cols;
    MazeObject* m_mazeObject;
    Maze* m_maze;
    QTimer* m_timer;
    const int m_step = 50;
};

#endif // GHOST_H
