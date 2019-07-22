#pragma once

#include <QMenu>

class Menu : public QMenu
{
	Q_OBJECT

public:
	explicit Menu(QWidget* parent = Q_NULLPTR);
	explicit Menu(const QString& title);
	~Menu();

protected:
	virtual bool event(QEvent* event);
};
