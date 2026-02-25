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
signals:
    void threadMsg( QString );
};

#endif // THREAD_H
