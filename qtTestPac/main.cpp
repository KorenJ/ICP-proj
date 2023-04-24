#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QKeyEvent>

// Model
class Pacman : public QGraphicsItem
{
public:
    Pacman() {}

    QRectF boundingRect() const override
    {
        return QRectF(-10, -10, 20, 20);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override
    {
        painter->setBrush(Qt::yellow);
        painter->drawEllipse(-10, -10, 20, 20);
    }
};

// View
class PacmanView : public QGraphicsView
{
public:
    PacmanView(QGraphicsScene *scene, QWidget *parent = nullptr)
        : QGraphicsView(scene, parent)
    {
        setRenderHint(QPainter::Antialiasing);
        setWindowTitle(tr("Pacman"));

        setFixedSize(640, 480);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    }

protected:
    void keyPressEvent(QKeyEvent *event) override
    {
        QList<QGraphicsItem *> items = scene()->items();
        foreach (QGraphicsItem *item, items)
        {
            if (Pacman *pacman = dynamic_cast<Pacman *>(item))
            {
                if (event->key() == Qt::Key_Left)
                    pacman->setPos(pacman->pos() + QPointF(-10, 0));
                else if (event->key() == Qt::Key_Right)
                    pacman->setPos(pacman->pos() + QPointF(10, 0));
                else if (event->key() == Qt::Key_Up)
                    pacman->setPos(pacman->pos() + QPointF(0, -10));
                else if (event->key() == Qt::Key_Down)
                    pacman->setPos(pacman->pos() + QPointF(0, 10));
            }
        }
    }
};

// Controller
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // create model
    Pacman pacman;

    // create scene
    QGraphicsScene scene;
    scene.addItem(&pacman);

    // create view
    PacmanView view(&scene);
    view.show();

    return app.exec();
}
