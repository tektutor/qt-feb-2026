#include <QPointer>
#include <QObject>
#include <QDebug>

class Worker : public QObject {
    Q_OBJECT
public:
    Worker() { qDebug() << "Worker created"; }
    ~Worker() { qDebug() << "Worker destroyed"; }

    void doWork();
};
