#include "TabDlg.h"

TabDlg::TabDlg(QString tabTitle ) {
	this->tabTitle = tabTitle;

	pListWidget = new QListWidget;

	pLayout = new QHBoxLayout;

	pLayout->addWidget ( pListWidget );

	setLayout ( pLayout );

	pThread = new Thread(tabTitle);
	isCreated = true;
	isRunning = false;

	connect (
		pThread,
		SIGNAL ( threadMsg( QString ) ),
		this,
		SLOT ( onThreadMessage( QString ) )
	);

}

void TabDlg::onStartThread(QString threadName) {
	if ( 0 == tabTitle.compare( threadName ) ) {
		pThread->start();
		isRunning = true;
	}
}

void TabDlg::onStopThread(QString threadName) {
	if ( 0 == tabTitle.compare( threadName ) ) {
		pThread->terminate();
		isRunning = false;
	}
}

void TabDlg::onThreadMessage( QString msg ) {
	pListWidget->addItem( msg );
}

bool TabDlg::isThreadRunning() {
	return isRunning;
}

bool TabDlg::isThreadCreated() {
	return isCreated;
}
