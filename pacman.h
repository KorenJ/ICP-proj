#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsItem>
#include <QPainter>
#include <QKeyEvent>
#include <QObject>
#include <headers/MazeObject.hpp>
#include <QTimer>

class Pacman :public QObject, public QGraphicsItem //public MazeObject
{
    Q_OBJECT
public:
    MazeObject *pacmanMove;
    Maze * m_maze;
    Pacman(MazeObject *pacman, Maze *maze, QTimer *mainTimer, QGraphicsItem *parent = nullptr);

    int quitNext = 0;
    int rows = 0;
    int cols = 0;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    void keyPressEvent(QKeyEvent *event) override;
public slots:
    void move();

private:
    enum class Dir {
        Up,
        Down,
        Left,
        Right,
    };


    const int m_step = 50;
    Direction lastDir = Direction::None;
};

#endif // PACMAN_H
