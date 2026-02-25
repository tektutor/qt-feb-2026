#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QString>
#include <QDebug>

class Thread : public QThread
{
    Q_OBJECT
private:
    QString name;
public:
    Thread(QString);
    void run();
};

#endif // THREAD_H
