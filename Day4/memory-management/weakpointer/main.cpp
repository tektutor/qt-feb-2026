#include <QCoreApplication>
#include "worker.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Create a shared pointer
    QSharedPointer<Worker> worker(new Worker());

    // Create a weak pointer observing the same object
    QWeakPointer<Worker> weakWorker(worker);

    // Lock weak pointer to get a shared pointer
    if (QSharedPointer<Worker> locked = weakWorker.toStrongRef()) {
        qDebug() << "Locked weak pointer, object is alive";
        locked->doWork();
    } else {
        qDebug() << "Object already deleted";
    }

    // Reset the shared pointer (object destroyed here)
    worker.clear();

    // Try locking again
    if (QSharedPointer<Worker> locked = weakWorker.toStrongRef()) {
        qDebug() << "Locked weak pointer, object is alive";
        locked->doWork();
    } else {
        qDebug() << "Object already deleted";
    }

    return 0;
}
