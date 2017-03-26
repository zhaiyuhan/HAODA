#include "stdafx.h"
#include "HAPPYPLAYER.h"
#include <dwmapi.h>
#pragma comment (lib,"Dwmapi.lib")
HAPPYPLAYER::HAPPYPLAYER(QWidget *parent)
	: QMainWindow(parent)
{
	InitView();
}

void HAPPYPLAYER::InitView()
{
	this->setMinimumSize(1024, 768);
	this->setWindowFlags(Qt::Window | Qt::WindowMinMaxButtonsHint | Qt::FramelessWindowHint);
	EnableWindowShadow(true);
	EnableGaussianBlur(true);
	EnableAnimation(true);
}

void HAPPYPLAYER::EnableTransparentBackground(bool ifEnable)
{
	QPalette p = palette();
	p.setColor(QPalette::Background, QColor(0x00, 0xff, 0x00, 0x00));
	this->setPalette(p);
}

void HAPPYPLAYER::EnableGaussianBlur(bool ifEnable)
{
	if (ifEnable)
	{
		EnableTransparentBackground(true);
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

void HAPPYPLAYER::EnableWindowShadow(bool ifEnable)
{
	if(ifEnable)
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

void HAPPYPLAYER::EnableAnimation(bool ifEnable)
{
	if (ifEnable)
	{	
	HWND hWnd = (HWND)this->winId();
	DWORD style = ::GetWindowLong(hWnd, GWL_STYLE);
	SetWindowLong(hWnd, GWL_STYLE, style | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CAPTION);
	}
}

bool HAPPYPLAYER::nativeEvent(const QByteArray & eventType, void * message, long * result)
{
	Q_UNUSED(eventType)

		MSG* msg = reinterpret_cast<MSG*>(message);

	int xPos = 0, yPos = 0;
	switch (msg->message)
	{
	case WM_NCHITTEST:
		xPos = GET_X_LPARAM(msg->lParam) - this->frameGeometry().x();
		yPos = GET_Y_LPARAM(msg->lParam) - this->frameGeometry().y();
		if (this->childAt(xPos, yPos) == 0)
		{
			*result = HTCAPTION;
		}
		else {
			return false;
		}
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
		if (::IsZoomed(msg->hwnd)) {

			RECT frame = { 0, 0, 0, 0 };
			AdjustWindowRectEx(&frame, WS_OVERLAPPEDWINDOW, FALSE, 0);
			frame.left = abs(frame.left);
			frame.top = abs(frame.bottom);
			this->setContentsMargins(frame.left, frame.top, frame.right, frame.bottom);
		}
		else {
			this->setContentsMargins(0, 0, 0, 0);
		}

		*result = ::DefWindowProc(msg->hwnd, msg->message, msg->wParam, msg->lParam);
		break;

	case WM_NCCALCSIZE:
		return true;
		break;
	default:
		return false;
	}
}
