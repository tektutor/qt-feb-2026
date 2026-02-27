#include <QScopedPointer>
#include <QDebug>

class Worker {
public:
    Worker() { qDebug() << "Worker created"; }
    ~Worker() { qDebug() << "Worker destroyed"; }

    void doWork();
};
