#pragma once

#include <QtWidgets\QMainWindow>
#include "Foundation\WindowCompositionAttribute.h"
#include "Foundation\BaseView\BaseView.h"
#include "BaseControlWidget\TitleBar.h"

#include "qevent.h"
#include <dwmapi.h>
#include <windowsx.h>
#include <qt_windows.h>
#include <qpalette.h>

class HAPPYPLAYER : public BaseView
{
	Q_OBJECT

public:
	explicit HAPPYPLAYER(QWidget *parent = Q_NULLPTR);

protected:
	void InitView();
	bool nativeEvent(const QByteArray &eventType, void *message, long *result);
	void changeEvent(QEvent *event);
	void resizeEvent(QResizeEvent *event);
	/*void paintEvent(QPaintEvent * event);*/
private:
	TitleBar *m_maintitlebar;
};
