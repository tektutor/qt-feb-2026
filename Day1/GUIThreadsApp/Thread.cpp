#include "Thread.h"

Thread::Thread(QString name ) {
    this->name = name;
}

void Thread::run() {

    QString strMsg;
    QString strTemp;

    for ( int i=0; i<30000; ++i ) {
	strMsg = "Message from thread ";
	strMsg.append( name );

	strTemp.setNum ( i );
	strMsg.append ( strTemp );

        qDebug() << strMsg; 
	emit threadMsg( strMsg );
    }
}
