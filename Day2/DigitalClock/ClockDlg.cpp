#include "ClockDlg.h"

ClockDlg::ClockDlg() {

	setWindowTitle( "Digital Clock" );

	QTime time = QTime::currentTime();	
	hours = time.hour();
	minutes = time.minute();
	seconds = time.second();

	QString strHours, strMinutes, strSeconds;

	strHours.setNum( hours );
	strMinutes.setNum( minutes );
	strSeconds.setNum( seconds );

	pHoursLabel = new QLabel(strHours);
	pMinutesLabel = new QLabel(strMinutes);
	pSecondsLabel = new QLabel(strSeconds);

	pHourSeparator = new QLabel(":");
	pMinuteSeparator = new QLabel(":");

	const QFont font( "Seven Segment", 100, QFont::Bold );

	pHoursLabel->setFont( font );
	pMinutesLabel->setFont ( font );
	pSecondsLabel->setFont ( font );
	pHourSeparator->setFont ( font );
	pMinuteSeparator->setFont ( font );

	pLayout = new QHBoxLayout;

	pLayout->addWidget( pHoursLabel );
	pLayout->addWidget( pHourSeparator );
	pLayout->addWidget( pMinutesLabel );
	pLayout->addWidget( pMinuteSeparator );
	pLayout->addWidget( pSecondsLabel );

	setLayout ( pLayout );

	pTimer = new QTimer;
	pTimer->setInterval( 1000 );

	connect (
		pTimer,
		SIGNAL ( timeout() ),
		this,
		SLOT ( onTimerTriggered() )
	);

	pTimer->start();

}

void ClockDlg::onTimerTriggered() {
	//This slot method will be invoked every second by the timer
	hours = pHoursLabel->text().toInt();
	minutes = pMinutesLabel->text().toInt();
	seconds = pSecondsLabel->text().toInt();

	if ( seconds < 59 ) ++seconds;
	else {
		seconds = 0;
		if ( minutes < 59 )
			++minutes;
		else {
			minutes = 0;
			if ( hours < 12 ) ++ hours;
			else
				hours = 1;
		}
	}

	QString strHours, strMinutes, strSeconds;

	strHours.setNum( hours );
	strMinutes.setNum( minutes );
	strSeconds.setNum( seconds );

	pHoursLabel->setText( strHours );
	pMinutesLabel->setText( strMinutes );
	pSecondsLabel->setText( strSeconds );
	
}
