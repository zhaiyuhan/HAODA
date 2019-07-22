#pragma once

#include <QWidget>
#include <qt_windows.h>
#include <BaseControlWidget\TitleBar.h>
#include "qevent.h"
#include <dwmapi.h>
#include <windowsx.h>

class BaseView : public QWidget
{
	Q_OBJECT

public:
	explicit BaseView(QWidget *parent);
	~BaseView();
	
	void _init_view(int xheight, int xwidth,
		QColor backgroundcolor,
		bool ifEnableGaussianBlur,
		bool ifEnableWindowShadow,
		bool ifEnableAnimation);
	void createTitleBar(int h,QColor c,bool shadow);
protected:
	void _init_TitleBar(TitleBar * t, int xheight, QColor background, bool ifEnableShadow);
	void _init_titlebar_events(TitleBar *maintitlebar);
	bool nativeEvent(const QByteArray &eventType, void *message, long *result);
	void changeEvent(QEvent *event);
	void resizeEvent(QResizeEvent *event);
	void showEvent(QShowEvent* event)
	{
		this->setAttribute(Qt::WA_Mapped);
		QWidget::showEvent(event);

	}


	void mousePressEvent(QMouseEvent* event)
	{
#ifdef Q_OS_WIN
		if (ReleaseCapture())
			SendMessage(HWND(winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
		event->ignore();
#else
#endif
	}
	void EnableBackgroundColor(QColor bgcolor);
	void EnableGaussianBlur(bool ifEnable);
	void EnableWindowShadow(bool ifEnable);
	void EnableAnimation(bool ifEnable);
signals:
	void isHadFocuse(bool had);
	void togglebtnMax(bool iftoggle);

private:
	auto composition_enabled() -> bool {
		auto composition_enabled = FALSE;
		auto success = ::DwmIsCompositionEnabled(&composition_enabled) == S_OK;
		return composition_enabled && success;
	}
	auto ifMaximized(HWND hwnd) -> bool
	{
		WINDOWPLACEMENT placement{};
		if (!::GetWindowPlacement(hwnd, &placement)) { return false; }
		return placement.showCmd == SW_MAXIMIZE;
	}
	auto adjust_maximized_client_rect(HWND window, RECT& rect) -> void
	{
		if (!ifMaximized(window)) { return; }
		auto monitor = ::MonitorFromWindow(window, MONITOR_DEFAULTTONULL);
		if (!monitor) { return; }
		MONITORINFO monitor_info{};
		monitor_info.cbSize = sizeof(monitor_info);
		if (!::GetMonitorInfoW(monitor, &monitor_info)) { return; }
		rect = monitor_info.rcWork;
	}
	void setHeight(int height);
	int getHeight();
	void setWidth(int width);
	int getWidth();
	int m_height, m_width;


	TitleBar *m_maintitlebar;
	
};
