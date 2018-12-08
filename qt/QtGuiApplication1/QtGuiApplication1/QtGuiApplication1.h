#pragma once

#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QEvent>

#include "ui_QtGuiApplication1.h"

class QtGuiApplication1 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication1(QWidget *parent = Q_NULLPTR);

protected:
	void mousePressEvent(QMouseEvent *);

	void keyPressEvent(QKeyEvent *evt);

	bool event(QEvent *event);

	bool eventFilter(QObject *target, QEvent *e);

public slots:
	void myClickButton();

private:
	void msgbox(char* msg);

private:
	Ui::QtGuiApplication1Class ui;
};
