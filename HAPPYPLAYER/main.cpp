#include "stdafx.h"
#include "HAPPYPLAYER.h"
#include "PlayerView.h"
#include <QtWidgets/QApplication>
#include <common/common.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Config::setName(QString::fromLatin1("Player"));
	QTranslator translator;
	translator.load("happyplayer_zh.qm");
	a.installTranslator(&translator);
	PlayerView w;
	//w.setProperty("rendererId", rendererId_from_opt_name(vo.toLower()));
	w.show();
	return a.exec();
}
