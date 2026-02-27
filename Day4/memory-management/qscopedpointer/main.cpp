#include <QCoreApplication>
#include "worker.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // QScopedPointer takes ownership of the object
    QScopedPointer<Worker> worker(new Worker());

    // Use the object
    worker->doWork();

    // No need to manually delete — QScopedPointer will delete automatically
    // when it goes out of scope (end of main function)

    return 0;
}
