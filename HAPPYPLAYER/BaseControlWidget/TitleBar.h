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
protected:
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
	int SpacingValue = 10;
	int LeftValue = 10;
	int TopValue = 10;
	MOON *m_moon;
};
