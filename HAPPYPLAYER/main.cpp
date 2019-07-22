#include "stdafx.h"
#include "HAPPYPLAYER.h"
#include "PlayerView.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTranslator translator;
	translator.load("happyplayer_zh.qm");
	a.installTranslator(&translator);
	PlayerView w;
	w.show();
	return a.exec();
}
