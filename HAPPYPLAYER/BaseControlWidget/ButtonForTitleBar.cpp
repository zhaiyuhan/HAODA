#include "stdafx.h"
#include "ButtonForTitleBar.h"

ButtonForTitleBar::ButtonForTitleBar(QWidget *parent)
	: QPushButton(parent)
{
	e_status = NORMAL;
	_ifPress = false;
	this->setFlat(true);
}

ButtonForTitleBar::~ButtonForTitleBar()
{
}

void ButtonForTitleBar::setType(ButtonType type)
{
	e_type = type;
}

ButtonType ButtonForTitleBar::getType()
{
	return e_type;
}

void ButtonForTitleBar::changeStatus(ButtonStatus status)
{
	if (status == NOSTATUS) e_status = NOSTATUS;
	if (status == NORMAL)e_status = NORMAL;
}

void ButtonForTitleBar::toggleResizeButton(bool isMax)
{
	if (!isMax)_isMax = false; else _isMax = true;
}



void ButtonForTitleBar::mousePressEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton)
	{
		_ifPress = true;
		e_status = PRESS;
		update();
	}else if (event->button() == Qt::RightButton)
	{
		_ifRPress = true;
		e_status = PRESS;
		update();
	}
}

void ButtonForTitleBar::mouseReleaseEvent(QMouseEvent * event)
{
	if (_ifPress  && this->rect().contains(event->pos()))
	{
		_ifPress = false;
		e_status = ENTER;
		update();
		emit clicked();
	}else if (_ifRPress  && this->rect().contains(event->pos()))
	{
		_ifRPress = false;
		e_status = ENTER;
		update();
		emit RightButtonCliked();
	}
}

void ButtonForTitleBar::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	QPixmap pixmap;
	painter.setRenderHint(QPainter::Antialiasing, true);
	if (getType() == CLOSE)
	{
		switch (e_status)
		{
		case NORMAL:
			pixmap.load(":/new/prefix1/Res_ButtonForTitleBar/buttonCloseNORMAL.png");
			break;
		case ENTER:
			pixmap.load(":/new/prefix1/Res_ButtonForTitleBar/buttonCloseENTER.png");
			break;
		case PRESS:
			pixmap.load(":/new/prefix1/Res_ButtonForTitleBar/buttonClosePRESS.png");
			break;
		case NOSTATUS:
			pixmap.load(":/btnForTitleBar/Res_ButtonForTitleBar/btnNoStatus.png");
			break;
		default:
			pixmap.load(":/new/prefix1/Res_ButtonForTitleBar/buttonCloseNORMAL.png");
			break;
		}
	}
	else if (getType() == MIN)
	{
		switch (e_status)
		{
		case NORMAL:
			pixmap.load(":/new/prefix1/Res_ButtonForTitleBar/buttonMinNOMAL.png");
			break;
		case ENTER:
			pixmap.load(":/new/prefix1/Res_ButtonForTitleBar/buttonMinENTER.png");
			break;
		case PRESS:
			pixmap.load(":/new/prefix1/Res_ButtonForTitleBar/buttonMinPRESS.png");
			break;
		case NOSTATUS:
			pixmap.load(":/btnForTitleBar/Res_ButtonForTitleBar/btnNoStatus.png");
			break;
		default:
			pixmap.load(":/new/prefix1/Res_ButtonForTitleBar/buttonMinNOMAL.png");
			break;
		}
	}
	else if (getType() == MAX)
	{
		if (!_isMax) {
			switch (e_status)
			{
			case NORMAL:
				pixmap.load(":/btnForTitleBar/Res_ButtonForTitleBar/btnResize.png");
				break;
			case ENTER:
				pixmap.load(":/btnForTitleBar/Res_ButtonForTitleBar/btnResizeEnter.png");
				break;
			case PRESS:
				pixmap.load(":/btnForTitleBar/Res_ButtonForTitleBar/btnResizePress.png");
				break;
			case NOSTATUS:
				pixmap.load(":/btnForTitleBar/Res_ButtonForTitleBar/btnNoStatus.png");
				break;
			default:
				pixmap.load(":/btnForTitleBar/Res_ButtonForTitleBar/btnResize.png");
				break;
			}
		}
		else {
			switch (e_status)
			{
			case NORMAL:
				pixmap.load(":/btnForTitleBar/Res_ButtonForTitleBar/btnResize.png");
				break;
			case ENTER:
				pixmap.load(":/btnForTitleBar/Res_ButtonForTitleBar/btnResizeEnter_Full.png");
				break;
			case PRESS:
				pixmap.load(":/btnForTitleBar/Res_ButtonForTitleBar/btnResizePress_Full.png");
				break;
			case NOSTATUS:
				pixmap.load(":/btnForTitleBar/Res_ButtonForTitleBar/btnNoStatus.png");
				break;
			default:
				pixmap.load(":/btnForTitleBar/Res_ButtonForTitleBar/btnResize.png");
				break;
			}
		}
	}
	painter.drawPixmap(0, 0, 15, 15, pixmap);
}

void ButtonForTitleBar::enterEvent(QEvent *)
{
	if (e_status != NOSTATUS)
	e_status = ENTER;
	update();
}

void ButtonForTitleBar::leaveEvent(QEvent *)
{
	if (e_status != NOSTATUS)
	e_status = NORMAL;
	update();
}
