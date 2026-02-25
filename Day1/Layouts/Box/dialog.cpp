#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{

    pBttn1 = new QPushButton("Button 1");
    pBttn2 = new QPushButton("Button 2");
    pBttn3 = new QPushButton("Button 3");
    pBttn4 = new QPushButton("Button 4");
    pBttn5 = new QPushButton("Button 5");

    //This is the actual layout manager
    //While QHBoxLayout and QVBoxLayout are convenience classes of QBoxLayout
    //with fixed orientation
    //QBoxLayout::LeftToRight
    //QBoxLayout::RightToLeft
    //QBoxLayout::TopToBotton
    //QBoxLayout::BottomToTop orientations
    pLayout = new QBoxLayout(QBoxLayout::BottomToTop);

    pLayout->addWidget(pBttn1);
    pLayout->addWidget(pBttn2);
    pLayout->addWidget(pBttn3);
    pLayout->addWidget(pBttn4);
    pLayout->addWidget(pBttn5);

    setLayout(pLayout);

    //Connect the button clicked signal with the corresponding slot methods to support event handling
    connect (
            pBttn1,                 //Source of the signal
            SIGNAL(clicked(bool)),  //the signal(event) you wish to handle
            this,                   //the target object that is going to provide the slot(event handler) method
            SLOT(onButton1Clicked())//tells which event handler(slot) method must be invoked when the signal clicked is emitted
    );
    connect ( pBttn2, SIGNAL(clicked(bool)), this, SLOT(onButton2Clicked()));
    connect ( pBttn3, SIGNAL(clicked(bool)), this, SLOT(onButton3Clicked()));
    connect ( pBttn4, SIGNAL(clicked(bool)), this, SLOT(onButton4Clicked()));
    connect ( pBttn5, SIGNAL(clicked(bool)), this, SLOT(onButton5Clicked()));

}

void Dialog::onButton1Clicked() {
    qDebug() << "Button 1 clicked ..." ;
}

void Dialog::onButton2Clicked() {
    qDebug() << "Button 2 clicked ..." ;
}

void Dialog::onButton3Clicked() {
    qDebug() << "Button 3 clicked ..." ;
}

void Dialog::onButton4Clicked() {
    qDebug() << "Button 4 clicked ..." ;
}

void Dialog::onButton5Clicked() {
    qDebug() << "Button 5 clicked ..." ;
}

Dialog::~Dialog() {}
