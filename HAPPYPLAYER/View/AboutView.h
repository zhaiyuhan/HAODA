#pragma once

#include <BaseView.h>
namespace Ui { class AboutView; };

class AboutView : public BaseView
{
	Q_OBJECT

public:
	AboutView(QWidget *parent = Q_NULLPTR);
	~AboutView();
protected:
	void resizeEvent(QResizeEvent* event)
	{
		Q_UNUSED(event);
		//here are make the layout rule for the window control buttons
		btnClose->move(15, 15);
	}
private:
	Ui::AboutView *ui;
	ButtonForTitleBar* btnClose;
	QButtonGroup* m_mainButtonGroup;
};
