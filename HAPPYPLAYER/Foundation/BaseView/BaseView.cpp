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

	case WM_NCCREATE: {
		auto userdata = reinterpret_cast<CREATESTRUCTW*>(msg->lParam)->lpCreateParams;
		::SetWindowLongPtrW(msg->hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(userdata));
	}
	case WM_NCCALCSIZE:
	{
		if (msg->wParam == TRUE)
		{
			auto& params = *reinterpret_cast<NCCALCSIZE_PARAMS*>(msg->lParam);
			adjust_maximized_client_rect(msg->hwnd, params.rgrc[0]);
		}
		*result = 0;
		return true;
	}
	case WM_NCHITTEST:
	{		
		*result = 0;
		const LONG border_width = 8; //in pixels
		RECT winrect;
		GetWindowRect(reinterpret_cast<HWND>(winId()), &winrect);

		long x = GET_X_LPARAM(msg->lParam);
		long y = GET_Y_LPARAM(msg->lParam);

		auto resizeWidth = minimumWidth() != maximumWidth();
		auto resizeHeight = minimumHeight() != maximumHeight();

		if (resizeWidth)
		{
			//left border
			if (x >= winrect.left && x < winrect.left + border_width)
			{
				*result = HTLEFT;
			}
			//right border
			if (x < winrect.right && x >= winrect.right - border_width)
			{
				*result = HTRIGHT;
			}
		}
		if (resizeHeight)
		{
			//bottom border
			if (y < winrect.bottom && y >= winrect.bottom - border_width)
			{
				*result = HTBOTTOM;
			}
			//top border
			if (y >= winrect.top && y < winrect.top + border_width)
			{
				*result = HTTOP;
			}
		}
		if (resizeWidth && resizeHeight)
		{
			//bottom left corner
			if (x >= winrect.left && x < winrect.left + border_width &&
				y < winrect.bottom && y >= winrect.bottom - border_width)
			{
				*result = HTBOTTOMLEFT;
			}
			//bottom right corner
			if (x < winrect.right && x >= winrect.right - border_width &&
				y < winrect.bottom && y >= winrect.bottom - border_width)
			{
				*result = HTBOTTOMRIGHT;
			}
			//top left corner
			if (x >= winrect.left && x < winrect.left + border_width &&
				y >= winrect.top && y < winrect.top + border_width)
			{
				*result = HTTOPLEFT;
			}
			//top right corner
			if (x < winrect.right && x >= winrect.right - border_width &&
				y >= winrect.top && y < winrect.top + border_width)
			{
				*result = HTTOPRIGHT;
			}
		}
		if (*result != 0)
			return true;
		break;
	}
	case WM_GETMINMAXINFO: {
		MINMAXINFO* mmi = reinterpret_cast<MINMAXINFO*>(msg->lParam);

		if (ifMaximized(msg->hwnd)) {

			RECT window_rect{};

			if (!GetWindowRect(msg->hwnd, &window_rect)) {
				return false;

			}

			HMONITOR monitor = MonitorFromRect(&window_rect, MONITOR_DEFAULTTONULL);
			if (!monitor) {
				return false;
			}

			MONITORINFO monitor_info = { 0 };
			monitor_info.cbSize = sizeof(monitor_info);
			GetMonitorInfo(monitor, &monitor_info);

			RECT work_area = monitor_info.rcWork;
			RECT monitor_rect = monitor_info.rcMonitor;

			mmi->ptMaxPosition.x = abs(work_area.left - monitor_rect.left);
			mmi->ptMaxPosition.y = abs(work_area.top - monitor_rect.top);

			mmi->ptMaxSize.x = abs(work_area.right - work_area.left);
			mmi->ptMaxSize.y = abs(work_area.bottom - work_area.top);
			mmi->ptMaxTrackSize.x = mmi->ptMaxSize.x;
			mmi->ptMaxTrackSize.y = mmi->ptMaxSize.y;

			*result = 1;
			return true;
		}
	}

	case WM_NCACTIVATE: {
		if (!composition_enabled()) {
			*result = 1;
			return true;
		}
		break;
	}
	case WM_SIZE: {

		RECT winrect;
		GetClientRect(msg->hwnd, &winrect);

		WINDOWPLACEMENT wp;
		wp.length = sizeof(WINDOWPLACEMENT);
		GetWindowPlacement(msg->hwnd, &wp);
		if (this)
		{
			if (wp.showCmd == SW_MAXIMIZE)
			{
				::SetWindowPos(reinterpret_cast<HWND>(winId()), Q_NULLPTR, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE);
			}
		}
	}
	case WM_SETFOCUS:
		emit isHadFocuse(true);
		break;
	case WM_KILLFOCUS:
		emit isHadFocuse(false);
		break;
	case WM_LBUTTONDBLCLK:
		if (!ifFixed)
		{
			if (Qt::WindowFullScreen == windowState())
				this->showNormal();
			if (Qt::WindowFullScreen != windowState())
				this->isMaximized() ? this->showNormal() : this->showMaximized();
		}
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
	/*m_maintitlebar->setFixedWidth(this->width());
	m_maintitlebar->move(0, 0);*/
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


