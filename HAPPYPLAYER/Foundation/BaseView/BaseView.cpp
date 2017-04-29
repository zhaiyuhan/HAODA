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

void BaseView::_init_TitleBar(int xheight, QColor background, bool ifEnableShadow)
{
		m_maintitlebar = new TitleBar(this);
}

bool BaseView::nativeEvent(const QByteArray & eventType, void * message, long * result)
{
	Q_UNUSED(eventType)
		MSG* msg = reinterpret_cast<MSG*>(message);
	int xPos = 0, yPos = 0;
	switch (msg->message)
	{
	case WM_NCHITTEST:
		xPos = GET_X_LPARAM(msg->lParam) - this->frameGeometry().x();
		yPos = GET_Y_LPARAM(msg->lParam) - this->frameGeometry().y();
		if (childAt(xPos, yPos) != NULL)
			return QWidget::nativeEvent(eventType, message, result);
		if (Qt::WindowFullScreen != windowState())
			*result = HTCAPTION;
		if (Qt::WindowFullScreen == windowState())
			*result = HTCLIENT;
		if (xPos > 0 && xPos < 5)
			*result = HTLEFT;
		if (xPos >(this->width() - 5) && xPos < (this->width() - 0))
			*result = HTRIGHT;
		if (yPos > 0 && yPos < 5)
			*result = HTTOP;
		if (yPos >(this->height() - 5) && yPos < (this->height() - 0))
			*result = HTBOTTOM;
		if (xPos > 0 && xPos < 5 && yPos > 0 && yPos < 5)
			*result = HTTOPLEFT;
		if (xPos >(this->width() - 5) && xPos < (this->width() - 0) && yPos > 0 && yPos < 5)
			*result = HTTOPRIGHT;
		if (xPos > 0 && xPos < 5 && yPos >(this->height() - 5) && yPos < (this->height() - 0))
			*result = HTBOTTOMLEFT;
		if (xPos >(this->width() - 5) && xPos < (this->width() - 0) && yPos >(this->height() - 5) && yPos < (this->height() - 0))
			*result = HTBOTTOMRIGHT;

		return true;
		break;

	case WM_GETMINMAXINFO:
		/*if (::IsZoomed(msg->hwnd)) {
		RECT frame = { 0, 0, 0, 0 };
		AdjustWindowRectEx(&frame, WS_OVERLAPPEDWINDOW, FALSE, 0);
		frame.left = abs(frame.left);
		frame.top = abs(frame.bottom);
		this->setContentsMargins(frame.left, frame.top, frame.right, frame.bottom);
		}
		else {
		this->setContentsMargins(0, 0, 0, 0);
		}
		*result = ::DefWindowProc(msg->hwnd, msg->message, msg->wParam, msg->lParam);*/
	{
		MINMAXINFO *mmi = (MINMAXINFO*)(msg->lParam);

		QRect desktop = qApp->desktop()->availableGeometry(this);
		QRect desktopRect = qApp->desktop()->screenGeometry(this);

		mmi->ptMaxSize.x = desktop.width();
		mmi->ptMaxSize.y = desktop.height();

		int desktopLeft = desktop.left() - desktopRect.left();
		int desktopTop = desktop.top() - desktopRect.top();

		mmi->ptMaxPosition.x = desktopLeft;
		mmi->ptMaxPosition.y = desktopTop;

		mmi->ptMinTrackSize.x = 1024;
		mmi->ptMinTrackSize.y = 768;

		mmi->ptMaxTrackSize.x = desktop.width();
		mmi->ptMaxTrackSize.y = desktop.height();

		*result = 0;

		return true;
	}
	break;

	case WM_SIZE:
		switch (msg->wParam)
		{
		case SIZE_MAXIMIZED:

			break;
		case SIZE_RESTORED:

			break;
		}
		break;
	case WM_NCCALCSIZE:
		return true;
		break;
	case WM_SETFOCUS:
		m_maintitlebar->setStatus(NORMAL);
		update();
		break;
	case WM_KILLFOCUS:
		m_maintitlebar->setStatus(NOSTATUS);
		update();
		break;
	case WM_LBUTTONDBLCLK:
		if (Qt::WindowFullScreen == windowState())
			this->showNormal();
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
		//if (Qt::WindowNoState == windowState()) m_maintitlebar->move(0, 0);
		if (Qt::WindowMaximized == windowState()) m_maintitlebar->setbtnMaxType(true);
		m_maintitlebar->move(6, 6);
		if (Qt::WindowMaximized != windowState()) m_maintitlebar->setbtnMaxType(false);
		if (Qt::WindowFullScreen == windowState()) m_maintitlebar->setbtnMaxType(true);
		if (Qt::WindowFullScreen != windowState()) m_maintitlebar->setbtnMaxType(false);
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
