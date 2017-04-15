#pragma once

#include <QWidget>
#include <qt_windows.h>

class BaseView : public QWidget
{
	Q_OBJECT

public:
	explicit BaseView(QWidget *parent);
	~BaseView();

	void Init_View(int xheight, int xwidth,
		QColor backgroundcolor,
		bool ifEnableGaussianBlur,
		bool ifEnableWindowShadow,
		bool ifEnableAnimation);
protected:

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
};
