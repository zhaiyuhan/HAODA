#pragma once

#include <QPushButton>

class QPushButton;
enum ButtonType { CLOSE, MIN, MAX };
enum ButtonStatus { NORMAL, ENTER, PRESS, NOSTATUS };
class ButtonForTitleBar : public QPushButton
{
	Q_OBJECT

public:
	ButtonForTitleBar(QWidget *parent);
	~ButtonForTitleBar();
	void setType(ButtonType type);
	ButtonType getType();
	void changeStatus(ButtonStatus status);
	void toggleResizeButton(bool isMax);
 signals:
	void RightButtonCliked();
protected slots :
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *);
	void enterEvent(QEvent *);
	void leaveEvent(QEvent *);
private:	
	ButtonStatus e_status;
	ButtonType e_type;
	bool _ifPress = false;
	bool _ifRPress = false;
	bool _isMax = false;
};
