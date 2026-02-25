#include <QCoreApplication>
#include "thread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Thread t1("Thread 1"), t2("Thread 2"), t3("Thread 3");
    t1.start();
    t2.start();
    t3.start();

    return a.exec();
}
