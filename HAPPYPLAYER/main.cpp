#include "stdafx.h"
#include "HAPPYPLAYER.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	HAPPYPLAYER w;
	w.show();
	return a.exec();
}
