#include "stdafx.h"
#include "TitleBar.h"
#include <windowsx.h>


TitleBar::TitleBar(QWidget *parent)
	: QWidget(parent)
{
	
}

TitleBar::~TitleBar()
{
}

void TitleBar::setStatus(ButtonStatus statusx)
{
	switch (statusx)
	{
	case NORMAL:
		btnClose->changeStatus(NORMAL);
		btnMin->changeStatus(NORMAL);
		btnMax->changeStatus(NORMAL);
		break;
	case NOSTATUS:
		btnClose->changeStatus(NOSTATUS);
		btnMin->changeStatus(NOSTATUS);
		btnMax->changeStatus(NOSTATUS);
		break;
	default:
		btnClose->changeStatus(NORMAL);
		btnMin->changeStatus(NORMAL);
		btnMax->changeStatus(NORMAL);
		break;
	}
}

void TitleBar::setbtnMaxType(bool isMax)
{
	btnMax->toggleResizeButton(isMax);
	if (isMax){
		btnMax->setToolTip(QString::fromLocal8Bit("向下还原"));
	}
	else{
		btnMax->setToolTip(QString::fromLocal8Bit("全屏"));
	}
}

void TitleBar::setHeight(int height)
{
	qDebug() << height;
	m_height = height;
}

void TitleBar::setColor(QColor bgcolor)
{
	m_bgcolor = bgcolor;
}

void TitleBar::EnableShaow(bool ifEnable)
{
	m_ifEnableShadow = ifEnable;
}

bool TitleBar::isCaption(int x, int y) const
{
	if (this->rect().contains(x, y)) {
		if (!this->childAt(x, y)) {
			return true;
		}
	}
	return false;
}

void TitleBar::showEvent(QShowEvent * event)
{
	Q_UNUSED(event);
	InitView();
	SetupEvents();
	SetupEffects();
}

void TitleBar::mouseDoubleClickEvent(QMouseEvent * event)
{
	Q_UNUSED(event);
	switch (parentWidget()->windowState())
	{
	case Qt::WindowNoState:
		parentWidget()->showMaximized();
		break;
	case Qt::WindowMaximized:
		parentWidget()->showNormal();
		break;
	case Qt::WindowFullScreen:
		parentWidget()->showNormal();
		break;
	default:
		parentWidget()->showNormal();
		break;
	}
}

void TitleBar::mousePressEvent(QMouseEvent * event)
{
	if (ReleaseCapture())
	{
		if (this->window()->isTopLevel()&& Qt::WindowFullScreen != this->window()->windowState())
		{
			SendMessage(HWND(this->window()->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
		}
	}
	event->ignore();
}

void TitleBar::InitView()
{
	setHeight(m_height);
	//setAutoFillBackground(true);
	SetupUI();
	btnClose->move(LeftValue, height() - 20);
	btnMin->move(LeftValue + btnClose->width() + SpacingValue, height() - 20);
	btnMax->move(LeftValue + btnMin->width() + btnMax->width() + 2 * SpacingValue, height() - 20);
	btnClose->show();
	btnMin->show();
	btnMax->show();
}

void TitleBar::SetupUI()
{
	btnClose = new ButtonForTitleBar(this);
	btnClose->setType(CLOSE);
	btnClose->setFixedSize(20, 20);
	btnClose->setToolTip(QString::fromLocal8Bit("关闭"));
	
	btnMin = new ButtonForTitleBar(this);
	btnMin->setType(MIN);
	btnMin->setFixedSize(20, 20);
	btnMin->setToolTip(QString::fromLocal8Bit("最小化"));
	
	btnMax = new ButtonForTitleBar(this);
	btnMax->setType(FULLSCREEN);
	btnMax->setFixedSize(20, 20);
	btnMax->setToolTip(QString::fromLocal8Bit("全屏"));
	
}

void TitleBar::SetupEvents()
{
	this->installEventFilter(this);
	connect(btnClose, &QPushButton::clicked, [=]() { qApp->exit(); });
	connect(btnMin, &QPushButton::clicked, [=]() { this->parentWidget()->showMinimized(); });
	connect(btnMax, &QPushButton::clicked, [=]()
	{ parentWidget()->isFullScreen() ? parentWidget()->showNormal() : parentWidget()->showFullScreen(); update();});

	connect(btnMax, &ButtonForTitleBar::RightButtonCliked, [=](){m_moon = new MOON(this);
	m_moon->move(parentWidget()->mapToGlobal(QPoint(0, 0)).x() + 60, parentWidget()->mapToGlobal(QPoint(0, 0)).y() + 30);
		m_moon->show(); });
}

void TitleBar::SetupEffects()
{
	CustomShadowEffect *bodyShadow = new CustomShadowEffect();
	bodyShadow->setBlurRadius(50.0);
	bodyShadow->setDistance(10.0);
	bodyShadow->setColor(QColor(0, 0, 0, 100));
	setGraphicsEffect(bodyShadow);
}

void TitleBar::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event);

	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing, true);
	p.fillRect(this->rect(), m_bgcolor);
}