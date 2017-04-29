#pragma once

#include <QWidget>
#include <qt_windows.h>
#include <BaseControlWidget\TitleBar.h>
#include "qevent.h"
#include <dwmapi.h>
#include <windowsx.h>

class BaseView : public QWidget
{
	Q_OBJECT

public:
	explicit BaseView(QWidget *parent);
	~BaseView();

	void _init_view(int xheight, int xwidth,
		QColor backgroundcolor,
		bool ifEnableGaussianBlur,
		bool ifEnableWindowShadow,
		bool ifEnableAnimation);
	void _init_TitleBar(int xheight, QColor background, bool ifEnableShadow);
protected:
	bool nativeEvent(const QByteArray &eventType, void *message, long *result);
	void changeEvent(QEvent *event);
	void resizeEvent(QResizeEvent *event);

	void EnableBackgroundColor(QColor bgcolor);
	void EnableGaussianBlur(bool ifEnable);
	void EnableWindowShadow(bool ifEnable);
	void EnableAnimation(bool ifEnable);

private:
	void setHeight(int height);
	int getHeight();
	void setWidth(int width);
	int getWidth();
	int m_height, m_width;


	TitleBar *m_maintitlebar;
};
