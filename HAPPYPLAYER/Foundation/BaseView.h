#pragma once

#include <QObject>
#include <QPoint>
#include <QSize>
#include <QColor>
#include <QSizePolicy>
#include <QPainter>
#include <QPainterPath>
#include <QCursor>
#include <QEvent>
#include <QMouseEvent>
#include <QPaintEvent>

#include <QtMath>

#include <windows.h>
#include <windowsx.h>

class BaseView : public QWidget
{
	Q_OBJECT

public:
	BaseView(QWidget *parent = 0);
	~BaseView();

private:
	bool nativeEvent(const QByteArray &eventType, void *message, long *result);
};
