#include "thread.h"

Thread::Thread(QString name ) {
    this->name = name;
}

void Thread::run() {

    for ( int i=0; i<30000; ++i ) {
        qDebug() << "Message from thread " << name << i;
    }
}
