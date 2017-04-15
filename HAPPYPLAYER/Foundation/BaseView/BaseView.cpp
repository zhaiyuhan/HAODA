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

void BaseView::Init_View(int xwidth, int xheight,
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
