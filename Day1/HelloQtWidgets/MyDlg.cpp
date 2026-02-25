#include "MyDlg.h"

MyDlg::MyDlg() {
	pBttn1 = new QPushButton("Button 1");
	pBttn2 = new QPushButton("Button 2");
	pBttn3 = new QPushButton("Button 3");

	//is an invisible canvas
	//we will arrange/render all the 
	//widgets in the layout
	//in order to add them later in a dialog
	//this layout manager will arrange
	//widgets in left to right fashion 
	//within in a single row
	pLayout = new QHBoxLayout;

	pLayout->addWidget ( pBttn1 );
	pLayout->addWidget ( pBttn2 );
	pLayout->addWidget ( pBttn3 );

	setLayout ( pLayout );
}

MyDlg::~MyDlg() {

}
