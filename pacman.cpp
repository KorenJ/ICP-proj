#include "pacman.h"
#include <QTime>
#include <QGraphicsScene>
#include <headers/MazeObject.hpp>
#include <headers/Field.hpp>
#include <QDebug>

Pacman::Pacman(MazeObject *pacman, Maze *maze, QGraphicsItem *parent) : QGraphicsItem(parent)
{
    pacmanMove = pacman;
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

QRectF Pacman::boundingRect() const
{
    return QRectF(0, 0, m_step, m_step);
}

void Pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::yellow);
    painter->drawPie(boundingRect(), 45 * 16, 270 * 16);
}

void Pacman::keyPressEvent(QKeyEvent *event)
{
    int x = pos().x() / m_step;
    int y = pos().y() / m_step;

    if (event->key() == Qt::Key_Left && x > 0) {
        if(pacmanMove->canMove(Direction::L)){
           setPos((x - 1) * m_step, y * m_step);
            pacmanMove->move(Direction::L);
        }
        //SLOT(moveLeft/canmove)->return next action
        //this->canMove(L);
        qDebug() << "PRESSED";
    } else if (event->key() == Qt::Key_Right && x < 9) {
        if(pacmanMove->canMove(Direction::R)){
            setPos((x + 1) * m_step, y * m_step);
            pacmanMove->move(Direction::R);
        }
    } else if (event->key() == Qt::Key_Up && y > 0) {
        if(pacmanMove->canMove(Direction::U)){
            setPos(x * m_step, (y - 1) * m_step);
            pacmanMove->move(Direction::U);
        }
    } else if (event->key() == Qt::Key_Down && y < 9) {
        if(pacmanMove->canMove(Direction::D)){
            setPos(x * m_step, (y + 1) * m_step);
            pacmanMove->move(Direction::D);
        }
    } else {
        QGraphicsItem::keyPressEvent(event);
    }

}
