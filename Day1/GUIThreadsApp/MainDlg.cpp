#include "MainDlg.h"

MainDlg::MainDlg() {

	tabIndex = 0;

	pTopLayout = new QHBoxLayout;
	pTabWidget = new QTabWidget;
	pTopLayout->addWidget ( pTabWidget );

	pBottomLayout = new QHBoxLayout;
	pNewThreadBttn = new QPushButton("New Thread");
	pStartBttn = new QPushButton("Start Thread");
	pStopBttn = new QPushButton("Stop Thread");
	pExitBttn = new QPushButton("Exit App");

	pBottomLayout->addStretch();
	pBottomLayout->addWidget ( pNewThreadBttn );
	pBottomLayout->addWidget ( pStartBttn );
	pBottomLayout->addWidget ( pStopBttn );
	pBottomLayout->addWidget ( pExitBttn );

	pMainLayout = new QVBoxLayout;
	pMainLayout->addLayout ( pTopLayout );
	pMainLayout->addLayout ( pBottomLayout );

	setLayout ( pMainLayout );

	connect (
		pNewThreadBttn,
		SIGNAL( clicked() ),
		this,
		SLOT ( onNewThreadButtonClicked() )
	);
	connect (
		pStartBttn,
		SIGNAL( clicked() ),
		this,
		SLOT ( onStartThreadButtonClicked() )
	);
	connect (
		pStopBttn,
		SIGNAL( clicked() ),
		this,
		SLOT ( onStopThreadButtonClicked() )
	);
	connect (
		pExitBttn,
		SIGNAL( clicked() ),
		this,
		SLOT ( onExitAppButtonClicked() )
	);
}
void MainDlg::onNewThreadButtonClicked() {
	qDebug() << "New Thread Button clicked ...";

	QString strTabTitle = "Thread ";
	QString strTemp;
	strTemp.setNum( ++tabIndex );
	strTabTitle.append( strTemp );

	TabDlg *pTabDlg = new TabDlg(strTabTitle);

	pTabWidget->addTab( pTabDlg , strTabTitle );

	connect (
		this,
		SIGNAL ( startThread(QString) ),
		pTabDlg,
		SLOT ( onStartThread(QString) )
	);
	connect (
		this,
		SIGNAL ( stopThread(QString) ),
		pTabDlg,
		SLOT ( onStopThread(QString) )
	);

}
void MainDlg::onStartThreadButtonClicked() {
	qDebug() << "Start Thread Button clicked ...";

	emit startThread(pTabWidget->tabText( pTabWidget->currentIndex() ));

}

void MainDlg::onStopThreadButtonClicked() {
	qDebug() << "Stop Thread Button clicked ...";

	emit stopThread( pTabWidget->tabText ( pTabWidget->currentIndex() ) );
}


void MainDlg::onExitAppButtonClicked() {
	qDebug() << "Exit App Button clicked ...";
	QDialog::close();
}

MainDlg::~MainDlg() {

}
