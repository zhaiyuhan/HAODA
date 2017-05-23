#include "stdafx.h"
#include "ButtonForTitleBar.h"
#include "Foundation\FoundationControl.h"

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
	if (status == NORMAL) e_status = NORMAL;
}

void ButtonForTitleBar::toggleResizeButton(bool isMax)
{
	if (!isMax)_isFullScreened = false; else _isFullScreened = true;
}

bool ButtonForTitleBar::isCaption(int x, int y) const
{
	if (this->rect().contains(x, y)) {
		if (!this->childAt(x, y)) {
			return true;
		}
	}
	return false;
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
	switch (e_status)
	{
	case NORMAL:
		if (getType() == CLOSE) m_loadpath = FoundationControl::WCB::btnClose;
		if (getType() == MIN) m_loadpath = FoundationControl::WCB::btnMin;
		if (getType() == FULLSCREEN) m_loadpath = FoundationControl::WCB::btnFullScreen;
		pixmap.load(m_loadpath);
		break;
	case ENTER:
		if (getType() == CLOSE) m_loadpath = FoundationControl::WCB::btnCloseHover;
		if (getType() == MIN) m_loadpath = FoundationControl::WCB::btnMinHover;
		if (getType() == FULLSCREEN&&_isFullScreened==false) 
			m_loadpath = FoundationControl::WCB::btnFullScreenHover;
		if (getType() == FULLSCREEN&&_isFullScreened == true)
			m_loadpath = FoundationControl::WCB::btnReFullScreenHover;
		pixmap.load(m_loadpath);
		break;
	case PRESS:
		if (getType() == CLOSE) m_loadpath = FoundationControl::WCB::btnClosePress;
		if (getType() == MIN) m_loadpath = FoundationControl::WCB::btnMinPress;
		if (getType() == FULLSCREEN&&_isFullScreened == false)
			m_loadpath = FoundationControl::WCB::btnFullScreenPress;
		if (getType() == FULLSCREEN&&_isFullScreened == true)
			m_loadpath = FoundationControl::WCB::btnReFullScreenPress;
		pixmap.load(m_loadpath);
		break;
	case NOSTATUS:
		m_loadpath = FoundationControl::WCB::btnNoStatus;
		pixmap.load(m_loadpath);
		break;
	default:
		if (getType() == CLOSE) m_loadpath = FoundationControl::WCB::btnClose;
		if (getType() == MIN) m_loadpath = FoundationControl::WCB::btnMin;
		if (getType() == FULLSCREEN) m_loadpath = FoundationControl::WCB::btnFullScreen;
		pixmap.load(m_loadpath);
		break;
	}
	painter.drawPixmap(0, 0, 16, 16, pixmap);
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
