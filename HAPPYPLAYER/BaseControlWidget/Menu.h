#pragma once

#include <QMenu>

class Menu : public QMenu
{
	Q_OBJECT

public:
	explicit Menu(QWidget* parent = Q_NULLPTR);
	explicit Menu(const QString& title, QWidget* parent = Q_NULLPTR);
	~Menu();

protected:
	virtual bool event(QEvent* event);
private:
	void _init_()
	{
		QFile menustyle(":/MenuStyle.qss");
		if (menustyle.open(QFile::ReadOnly))
		{
			QString style = QLatin1String(menustyle.readAll());
			this->setStyleSheet(style);
			menustyle.close();
		}
	}
};
