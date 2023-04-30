 
#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsItem>
#include <QPainter>
#include <QKeyEvent>
#include <QObject>
#include <headers/MazeObject.hpp>

class Pacman :public QGraphicsItem //public MazeObject
{
public:
    MazeObject *pacmanMove;
    Pacman(MazeObject *pacman, Maze *maze, QGraphicsItem *parent = nullptr);


    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    enum class Dir {
        Up,
        Down,
        Left,
        Right
    };

    const int m_step = 50;
    Dir m_direction = Dir::Right;
};

#endif // PACMAN_H
