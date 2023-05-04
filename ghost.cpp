#include "ghost.h"
#include <QGraphicsScene>
#include <cstdlib>
#include <ctime>
#include <QApplication>

Ghost::Ghost(MazeObject* mazeGhost, Maze* maze, QTimer *mainTimer, QObject *parent) :
    QObject(parent),
    QGraphicsPixmapItem(),
    m_maze(maze),
    m_timer(new QTimer(this))
{
    m_mazeObject = mazeGhost;
    QPixmap pixmap("images/ghost.png");
    setPixmap(pixmap.scaled(QSize(50,50), Qt::KeepAspectRatio));

    // set up a timer to move the ghost every 500 milliseconds
    QTimer *m_timer = mainTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(move()));
    rows = maze->getRows()-2;
    cols = maze->getCols()-2;
}

void Ghost::move()
{
    // get the current row and column of the ghost in the maze
    int currentCol = pos().x() / m_step;
    int currentRow = pos().y() / m_step;

    // generate a random direction (up, down, left, or right)
    srand(time(nullptr));
    int direction = rand() % 4;

    if((m_maze->getField(currentRow, currentCol)->nextField(Direction::R)->get() != nullptr
         && m_maze->getField(currentRow, currentCol)->nextField(Direction::R)->get()->isPacman())
        || (m_maze->getField(currentRow, currentCol)->get() != nullptr
            && m_maze->getField(currentRow, currentCol)->get()->isPacman())){
        QApplication::quit();
    }
    // attempt to move the ghost in the chosen direction
    switch (direction) {
    case 0: // up
        if (m_mazeObject->move(Direction::U)) {
            if(currentRow > 0){
                setPos(currentCol * m_step, (currentRow - 1) * m_step);
                if((m_maze->getField(currentRow, currentCol)->nextField(Direction::U)->get() != nullptr
                   && m_maze->getField(currentRow, currentCol)->nextField(Direction::U)->get()->isPacman())
                    || (m_maze->getField(currentRow, currentCol)->get() != nullptr
                        && m_maze->getField(currentRow, currentCol)->get()->isPacman())){
                    QApplication::quit();
                }
            }
        }
        break;
    case 1: // down
        if (m_mazeObject->move(Direction::D)) {
            if(currentRow < rows){
            setPos(currentCol * m_step, (currentRow + 1) * m_step);
                if((m_maze->getField(currentRow, currentCol)->nextField(Direction::D)->get() != nullptr
                 && m_maze->getField(currentRow, currentCol)->nextField(Direction::D)->get()->isPacman())
                || (m_maze->getField(currentRow, currentCol)->get() != nullptr
                    && m_maze->getField(currentRow, currentCol)->get()->isPacman())){
                    QApplication::quit();
                }
            }
        }
        break;
    case 2: // left
        if (m_mazeObject->move(Direction::L)) {
            if(currentCol > 0){
                setPos((currentCol - 1) * m_step, currentRow * m_step);
                if((m_maze->getField(currentRow, currentCol)->nextField(Direction::L)->get() != nullptr
                    && m_maze->getField(currentRow, currentCol)->nextField(Direction::L)->get()->isPacman())
                    || (m_maze->getField(currentRow, currentCol)->get() != nullptr
                        && m_maze->getField(currentRow, currentCol)->get()->isPacman())){
                    QApplication::quit();
                }
            }
        }
        break;
    case 3: // right
        if (m_mazeObject->move(Direction::R)) {
            if(currentCol < cols){
                setPos((currentCol + 1) * m_step, currentRow * m_step);
                if((m_maze->getField(currentRow, currentCol)->nextField(Direction::R)->get() != nullptr
                     && m_maze->getField(currentRow, currentCol)->nextField(Direction::R)->get()->isPacman())
                    || (m_maze->getField(currentRow, currentCol)->get() != nullptr
                        && m_maze->getField(currentRow, currentCol)->get()->isPacman())){
                    QApplication::quit();
                }
            }
        }
        break;
    }
}
