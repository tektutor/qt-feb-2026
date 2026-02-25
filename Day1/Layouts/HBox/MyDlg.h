#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>

class MyDlg : public QDialog {
private:
	QPushButton *pBttn1, *pBttn2, *pBttn3;
	QVBoxLayout *pLayout;
public:
	MyDlg();
	~MyDlg();

};
