#include "stdafx.h"
#include "BaseView.h"

#pragma comment (lib,"Dwmapi.lib")

BaseView::BaseView(QWidget *parent)
	: QWidget(parent)
{
	this->setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::FramelessWindowHint);
}

BaseView::~BaseView()
{
}

void BaseView::_init_view(int xwidth, int xheight,
	QColor backgroundcolor,
	bool ifEnableGaussianBlur, 
	bool ifEnableWindowShadow, 
	bool ifEnableAnimation)
{
	setWidth(xwidth);
	setHeight(xheight);
	this->resize(getWidth(), getHeight());
	EnableBackgroundColor(backgroundcolor);
	if (ifEnableGaussianBlur) EnableGaussianBlur(true);
	if (ifEnableWindowShadow) EnableWindowShadow(true);
	if (ifEnableAnimation)EnableAnimation(true);
}

void BaseView::createTitleBar(int h, QColor c, bool shadow)
{
	m_maintitlebar = new TitleBar(this);
	m_maintitlebar->show();
	_init_TitleBar(m_maintitlebar, h, c, shadow);
}

void BaseView::_init_TitleBar(TitleBar *t, int xheight, QColor background, bool ifEnableShadow)
{
	_init_titlebar_events(t);
	t->setHeight(xheight);
	t->setColor(background);
	t->EnableShaow(ifEnableShadow);
	t->show();
}

void BaseView::_init_titlebar_events(TitleBar *maintitlebar)
{
	if (maintitlebar != nullptr)
	connect(this, &BaseView::isHadFocuse, [=](bool had) {
		if (had) {
			maintitlebar->setStatus(NORMAL);
			update();
		}
		else {
			maintitlebar->setStatus(NOSTATUS);
			update();
		}
	});
	connect(this, &BaseView::togglebtnMax, [=](bool iftoggle) {
		if (iftoggle) {
			maintitlebar->setbtnMaxType(true);
			maintitlebar->resize(this->width(), 30);
			update();
		}
		else {
			maintitlebar->setbtnMaxType(false);
			maintitlebar->resize(this->width(), 30);
			update();
		}
	});
}

bool BaseView::nativeEvent(const QByteArray & eventType, void * message, long * result)
{
	Q_UNUSED(eventType)
	MSG* msg = reinterpret_cast<MSG*>(message);
	switch (msg->message) {
	case WM_NCHITTEST:
	{
	int xPos = GET_X_LPARAM(msg->lParam) - this->frameGeometry().x();
	int yPos = GET_Y_LPARAM(msg->lParam) - this->frameGeometry().y();
	*result = HTCLIENT;
	if (xPos > 0 && xPos < 5)
		*result = HTLEFT;
	if (xPos > (this->width() - 5) && xPos < (this->width() - 0))
		*result = HTRIGHT;
	if (yPos > 0 && yPos < 5)
		*result = HTTOP;
	if (yPos > (this->height() - 5) && yPos < (this->height() - 0))
		*result = HTBOTTOM;
	if (xPos > 0 && xPos < 5 && yPos > 0 && yPos < 5)
		*result = HTTOPLEFT;
	if (xPos > (this->width() - 5) && xPos < (this->width() - 0) && yPos > 0 && yPos < 5)
		*result = HTTOPRIGHT;
	if (xPos > 0 && xPos < 5 && yPos >(this->height() - 5) && yPos < (this->height() - 0))
		*result = HTBOTTOMLEFT;
	if (xPos > (this->width() - 5) && xPos < (this->width() - 0) && yPos >(this->height() - 5) && yPos < (this->height() - 0))
		*result = HTBOTTOMRIGHT;
	return true;
	break;
	}
	/*
	case WM_GETMINMAXINFO:
	{
		if (::IsZoomed(msg->hwnd)) {
			qDebug() << "MAXED";
			this->setContentsMargins(6, 6, 6, 6);
		}
		else {
			this->setContentsMargins(6, 6, 6, 6);
		}
		*result = ::DefWindowProc(msg->hwnd, msg->message, msg->wParam, msg->lParam);
		return true;
	}
	break;
	*/
	case WM_SIZE:
		switch (msg->wParam)
		{
		case SIZE_MAXIMIZED:
			qDebug() << "Maxed";
			setContentsMargins(6, 6, 6, 6);
			break;
		case SIZE_RESTORED:
			qDebug() << "Restored";
			break;
		}
		break;
	case WM_NCCALCSIZE:
		return true;
		break;
	case WM_SETFOCUS:
		emit isHadFocuse(true);
		break;
	case WM_KILLFOCUS:
		emit isHadFocuse(false);
		break;
	case WM_LBUTTONDOWN:
		if (Qt::WindowFullScreen != windowState())
			if (ReleaseCapture())
		SendMessage(HWND(this->window()->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
		break;
	case WM_LBUTTONDBLCLK:
		if (Qt::WindowFullScreen == windowState())
			this->showNormal();
		if (Qt::WindowFullScreen != windowState())
		this->isMaximized() ? this->showNormal() : this->showMaximized();
		break;
	default:
		return QWidget::nativeEvent(eventType, message, result);
	}
	return QWidget::nativeEvent(eventType, message, result);
}

void BaseView::changeEvent(QEvent * event)
{
	Q_UNUSED(event);
	if (event->type() == QEvent::WindowStateChange)
	{
		if (Qt::WindowMaximized == windowState()) emit togglebtnMax(true);
		if (Qt::WindowMaximized != windowState()) emit togglebtnMax(false);
		if (Qt::WindowFullScreen == windowState()) emit togglebtnMax(true);
		if (Qt::WindowFullScreen != windowState()) emit togglebtnMax(false);
	}
}

void BaseView::resizeEvent(QResizeEvent * event)
{
	QWidget::resizeEvent(event);
	m_maintitlebar->setFixedWidth(this->width());
	m_maintitlebar->move(0, 0);
}

void BaseView::EnableBackgroundColor(QColor bgcolor)
{
	QPalette p = palette();
	//p.setColor(QPalette::Background, QColor(0x00, 0xff, 0x00, 0x00));
	p.setColor(QPalette::Background, bgcolor);
	this->setPalette(p);
}

void BaseView::EnableGaussianBlur(bool ifEnable)
{
	if (ifEnable)
	{
		HWND hWnd = HWND(winId());
		HMODULE hUser = GetModuleHandle(L"user32.dll");
		if (hUser)
		{
			pfnSetWindowCompositionAttribute setWindowCompositionAttribute =
				(pfnSetWindowCompositionAttribute)GetProcAddress(hUser, "SetWindowCompositionAttribute");
			if (setWindowCompositionAttribute)
			{
				ACCENT_POLICY accent = { ACCENT_ENABLE_BLURBEHIND, 0, 0, 0 };
				WINDOWCOMPOSITIONATTRIBDATA data;
				data.Attrib = WCA_ACCENT_POLICY;
				data.pvData = &accent;
				data.cbData = sizeof(accent);
				setWindowCompositionAttribute(hWnd, &data);
			}
		}
	}
}

void BaseView::EnableWindowShadow(bool ifEnable)
{
	if (ifEnable)
	{
		BOOL bEnable = false;
		::DwmIsCompositionEnabled(&bEnable);
		if (bEnable)
		{
			DWMNCRENDERINGPOLICY ncrp = DWMNCRP_ENABLED;
			::DwmSetWindowAttribute((HWND)winId(), DWMWA_NCRENDERING_POLICY, &ncrp, sizeof(ncrp));
			MARGINS margins = { -1 };
			::DwmExtendFrameIntoClientArea((HWND)winId(), &margins);
		}
	}
}

void BaseView::EnableAnimation(bool ifEnable)
{
	if (ifEnable)
	{
		HWND hWnd = (HWND)this->winId();
		DWORD style = ::GetWindowLong(hWnd, GWL_STYLE);
		SetWindowLong(hWnd, GWL_STYLE, style | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CAPTION | CS_DBLCLKS);
	}
}

void BaseView::setHeight(int height)
{
	m_height = height;
}

int BaseView::getHeight()
{
	return m_height;
}

void BaseView::setWidth(int width)
{
	m_width = width;
}

int BaseView::getWidth()
{
	return m_width;
}


