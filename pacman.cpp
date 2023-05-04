#include "pacman.h"
#include <QTime>
#include <QApplication>
#include <QGraphicsScene>
#include <headers/MazeObject.hpp>
#include <headers/Field.hpp>
#include <QDebug>
#include <QTimer>

Pacman::Pacman(MazeObject *pacman, Maze *maze, QTimer *mainTimer, QGraphicsItem *parent) :QGraphicsItem(parent)
{
    pacmanMove = pacman;
    m_maze = maze;
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    QTimer *m_timer = mainTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(move()));
    rows = maze->getRows() - 2;
    cols = maze->getCols() - 2;
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

void Pacman::move(){
    int x = pos().x() / m_step;
    int y = pos().y() / m_step;

    if((m_maze->getField(y, x)->nextField(Direction::U)->get() != nullptr
         && m_maze->getField(y, x)->nextField(Direction::U)->getGhost())
        || (m_maze->getField(y, x)->get() != nullptr
            && m_maze->getField(y, x)->getGhost())){
        QApplication::quit();
    }

    if (lastDir == Direction::L && x > 0) {
        if(pacmanMove->move(Direction::L)){
            setPos((x - 1) * m_step, y * m_step);
            if((m_maze->getField(y, x)->nextField(Direction::L)->get() != nullptr
                && m_maze->getField(y, x)->nextField(Direction::L)->getGhost())
                || (m_maze->getField(y, x)->get() != nullptr
                    && m_maze->getField(y, x)->getGhost())){
                QApplication::quit();
            }
        }
    }
    else if (lastDir == Direction::R && x < rows) {
        if(pacmanMove->move(Direction::R)){
            setPos((x + 1) * m_step, y * m_step);
            if((m_maze->getField(y, x)->nextField(Direction::R)->get() != nullptr
                && m_maze->getField(y, x)->nextField(Direction::R)->getGhost())
                || (m_maze->getField(y, x)->get() != nullptr
                    && m_maze->getField(y, x)->getGhost())){
                QApplication::quit();
            }
        }
    }
    else if (lastDir == Direction::U && y > 0) {
        if(pacmanMove->move(Direction::U)){
            setPos(x * m_step, (y - 1) * m_step);
            if((m_maze->getField(y, x)->nextField(Direction::U)->get() != nullptr
                && m_maze->getField(y, x)->nextField(Direction::U)->getGhost())
                || (m_maze->getField(y, x)->get() != nullptr
                    && m_maze->getField(y, x)->getGhost())){
                QApplication::quit();
            }
        }
    }
    else if(lastDir == Direction::D && y < cols) {
        if(pacmanMove->move(Direction::D)){
            setPos(x * m_step, (y + 1) * m_step);
            if((m_maze->getField(y, x)->nextField(Direction::D)->getGhost())
               || (m_maze->getField(y, x)->getGhost())){
                QApplication::quit();
            }
        }
    }
    if((m_maze->getField(y, x)->nextField(Direction::U)->get() != nullptr
         && m_maze->getField(y, x)->nextField(Direction::U)->getGhost())
        || (m_maze->getField(y, x)->get() != nullptr
            && m_maze->getField(y, x)->getGhost())){
        QApplication::quit();
    }
}

void Pacman::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "PRESSED";
    int x = pos().x() / m_step;
    int y = pos().y() / m_step;


    if (event->key() == Qt::Key_Left && x > 0) {
        if(pacmanMove->canMove(Direction::L)){
            lastDir = Direction::L;
        }
        //SLOT(moveLeft/canmove)->return next action
        //this->canMove(L);
    } else if (event->key() == Qt::Key_Right && x < rows) {
        if(pacmanMove->canMove(Direction::R)){
            lastDir = Direction::R;
        }
    } else if (event->key() == Qt::Key_Up && y > 0) {
        if(pacmanMove->canMove(Direction::U)){
            lastDir = Direction::U;
        }
    } else if (event->key() == Qt::Key_Down && y < cols) {
        if(pacmanMove->canMove(Direction::D)){
            lastDir = Direction::D;
        }
    } else {
        QGraphicsItem::keyPressEvent(event);
    }

}

