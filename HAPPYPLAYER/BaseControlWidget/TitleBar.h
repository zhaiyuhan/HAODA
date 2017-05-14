#pragma once

#include <QObject>
#include <qwidget.h>
#include "BaseControlWidget\ButtonForTitleBar.h"
#include "BaseControlWidget\MOON.h"


class TitleBar : public QWidget
{
	Q_OBJECT
public:
	explicit TitleBar(QWidget *parent = 0);
	~TitleBar();

	void setStatus(ButtonStatus statusx);
	void setbtnMaxType(bool isMax);
	void setHeight(int height);
	void setColor(QColor bgcolor);
	void EnableShaow(bool ifEnable);
protected:
	virtual void showEvent(QShowEvent *event);
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent * event);
private:
	void InitView();
	void SetupUI();
	void SetupEvents();
	void SetupEffects();
	ButtonForTitleBar *btnMin;
	ButtonForTitleBar *btnMax;
	ButtonForTitleBar *btnClose;
	int SpacingValue = 4;
	int LeftValue = 5;
	int TopValue = 5;
	int m_height;
	QColor m_bgcolor;
	bool m_ifEnableShadow;
	MOON *m_moon;
};
