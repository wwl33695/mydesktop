#include "QtGuiApplication1.h"
#include <QMessageBox>

QtGuiApplication1::QtGuiApplication1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.button2->installEventFilter(this);

	connect(ui.button1, SIGNAL(clicked()), this, SLOT(myClickButton()));
	//	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(find()));
}

void QtGuiApplication1::mousePressEvent(QMouseEvent *e)
{
	qDebug("pushButtonConnect");

	msgbox("mousePressEvent");
}

void QtGuiApplication1::keyPressEvent(QKeyEvent *e)
{
	qDebug("pushButtonConnect");

	msgbox("keyPressEvent");
}

bool QtGuiApplication1::event(QEvent *event)
{
	qDebug("pushButtonConnect");

	return QMainWindow::event(event);
}

void QtGuiApplication1::myClickButton()
{
	msgbox("myClickButton");
}

bool QtGuiApplication1::eventFilter(QObject *target, QEvent *e)
{
	if (target == ui.button2)
	{
		if (e->type() == QEvent::KeyPress) {
			QKeyEvent *ke = static_cast<QKeyEvent *>(e);
			if (ke->key() == Qt::Key_Tab) {
				// special tab handling here
				return true;
			}
		}
		else if (e->type() == QEvent::MouseButtonPress) {
			QMouseEvent *event = (QMouseEvent*)e;;

			if (event->button() == Qt::LeftButton) {
				// handle left mouse button here
				msgbox("eventFilter button2 left");
			}
			else {
				msgbox("eventFilter button2 not left");
			}

		}
	}
	return QMainWindow::eventFilter(target, e);

}

void QtGuiApplication1::msgbox(char* msg)
{
	QMessageBox *msgBox = new QMessageBox("title",		///--������������Ϣ�����
		msg,						///--������������Ϣ����ʾ������
		QMessageBox::Critical,							///--����������Ϣ����ʾ��ͼ��
		QMessageBox::Ok | QMessageBox::Default,		///---��������ʾ��Ϣ���ϵİ�ť���
		QMessageBox::Cancel | QMessageBox::Escape,	///---������ �����ϵ� escape ����ϡ����û����¸ü�����Ϣ��ִ��cancel��ť�¼�
		0);														///---������ �����������ť�� ������ ֻ�� ����ʾ2����ť

	msgBox->show();
}