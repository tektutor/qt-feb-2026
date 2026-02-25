#include "TabDlg.h"

TabDlg::TabDlg(QString tabTitle ) {
	this->tabTitle = tabTitle;

	pListWidget = new QListWidget;

	pLayout = new QHBoxLayout;

	pLayout->addWidget ( pListWidget );

	setLayout ( pLayout );

	pThread = new Thread(tabTitle);

	connect (
		pThread,
		SIGNAL ( threadMsg( QString ) ),
		this,
		SLOT ( onThreadMessage( QString ) )
	);
}

void TabDlg::onStartThread(QString threadName) {
	if ( 0 == tabTitle.compare( threadName ) )
		pThread->start();
}

void TabDlg::onStopThread(QString threadName) {
	if ( 0 == tabTitle.compare( threadName ) )
		pThread->terminate();
}

void TabDlg::onThreadMessage( QString msg ) {
	pListWidget->addItem( msg );
}
