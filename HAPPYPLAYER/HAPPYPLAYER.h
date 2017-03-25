#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HAPPYPLAYER.h"

class HAPPYPLAYER : public QMainWindow
{
	Q_OBJECT

public:
	HAPPYPLAYER(QWidget *parent = Q_NULLPTR);

private:
	Ui::HAPPYPLAYERClass ui;
};
