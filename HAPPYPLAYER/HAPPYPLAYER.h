#pragma once

#include <QtWidgets\QMainWindow>
#include "Foundation\WindowCompositionAttribute.h"
#include "Foundation\BaseView\BaseView.h"
#include "BaseControlWidget\TitleBar.h"
#include "BaseControlWidget\Menu.h"

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
	void contextMenuEvent(QContextMenuEvent*);
	Menu* menu;

};
