#include <QCoreApplication>
#include "worker.h"

void useWorker(QSharedPointer<Worker> workerPtr) {
    workerPtr->doWork();
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Create a shared pointer to Worker
    QSharedPointer<Worker> worker(new Worker());

    // Pass shared pointer to a function
    useWorker(worker);

    qDebug() << "After function call ";

    {
        // Create another shared pointer pointing to the same object
        QSharedPointer<Worker> anotherWorker = worker;
        anotherWorker->doWork();
    } // anotherWorker goes out of scope here

    // When 'worker' goes out of scope at the end of main,
    // the Worker object will be destroyed automatically.

    return 0;
}
