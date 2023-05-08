#ifndef LOG_H
#define LOG_H

#include <QObject>
#include <QTime>
#include <QTimer>
#include <chrono>
#include "headers/MazeObject.hpp"
#include "headers/Maze.hpp"


class Log :  public QObject
{
    Q_OBJECT
public:
    int logIteration = 1;

    int readingLogFromStart = 1;
    /**
     * The timeline for creating log files.
     */
    QTimer timeline ;

    /**
     * The maze to log.
     */
    Maze* m_maze;

    Maze* mazeLog;

    /**
     * The number of rows in the maze.
     */
    int m_rows;

    /**
     * The number of columns in the maze.
     */
    int m_cols;

    void clearLogFolder();

    void readSourceLog(int iteration);

    int countLogs();


    /**
     * Creates a new Log object with the specified maze, number of rows, and number of columns.
     *
     * @param maze the maze to log
     * @param rows the number of rows in the maze
     * @param cols the number of columns in the maze
     */
    Log(Maze* maze, int rows, int cols, QTimer *timer);

public slots:
    /**
     * Creates a log file for the current iteration.
     */
    void createLog();
};

#endif // LOG_H
