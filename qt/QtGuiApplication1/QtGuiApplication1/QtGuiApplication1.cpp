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
	QMessageBox *msgBox = new QMessageBox("title",		///--这里是设置消息框标题
		msg,						///--这里是设置消息框显示的内容
		QMessageBox::Critical,							///--这里是在消息框显示的图标
		QMessageBox::Ok | QMessageBox::Default,		///---这里是显示消息框上的按钮情况
		QMessageBox::Cancel | QMessageBox::Escape,	///---这里与 键盘上的 escape 键结合。当用户按下该键，消息框将执行cancel按钮事件
		0);														///---这里是 定义第三个按钮， 该例子 只是 了显示2个按钮

	msgBox->show();
}