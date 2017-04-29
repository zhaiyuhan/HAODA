#include "stdafx.h"
#include "HAPPYPLAYER.h"


HAPPYPLAYER::HAPPYPLAYER(QWidget *parent)
	: BaseView(parent)
{
	InitView();
}

void HAPPYPLAYER::InitView()
{
	_init_view(1024, 768, QColor(255,255,255,100), true, true, true);
	_init_TitleBar(30, QColor(255, 255, 255, 80), true);
	setMouseTracking(true);
}








