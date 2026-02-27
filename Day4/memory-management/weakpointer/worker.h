#include <QSharedPointer>
#include <QWeakPointer>
#include <QDebug>

class Worker {
public:
    Worker() { qDebug() << "Worker created"; }
    ~Worker() { qDebug() << "Worker destroyed"; }

    void doWork(); 
};
