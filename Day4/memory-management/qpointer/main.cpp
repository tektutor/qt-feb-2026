#include <QCoreApplication>
#include "worker.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Create a QObject dynamically
    Worker *rawWorker = new Worker();

    // Wrap it in a QPointer
    QPointer<Worker> safeWorker(rawWorker);

    // Use the object
    if (safeWorker) {
        safeWorker->doWork();
    }

    // Delete the raw pointer manually
    delete rawWorker;

    // Now QPointer automatically becomes nullptr
    if (safeWorker) {
        safeWorker->doWork();
    } else {
        qDebug() << "safeWorker is null, object already deleted!";
    }

    return 0;
}

