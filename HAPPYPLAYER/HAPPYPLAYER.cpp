#include "stdafx.h"
#include "HAPPYPLAYER.h"


HAPPYPLAYER::HAPPYPLAYER(QWidget *parent)
	: BaseView(parent)
{
	InitView();
}

void HAPPYPLAYER::InitView()
{
	_init_view(1024, 768, QColor(255,255,255,100), false, true, true);
	createTitleBar(20, QColor(255, 255, 255, 80), true);
	setMouseTracking(true);
}

void HAPPYPLAYER::contextMenuEvent(QContextMenuEvent*)
{
	QCursor cur = this->cursor();
	menu = new Menu(this);
	QAction* OpenAction = new QAction(tr("Open"), this);

	QAction* OpenAudioCDAction = new QAction(tr("Open audio CD"), this);
	QAction* AddFilesAction = new QAction(tr("Add Files"), this);
	QAction* AddFloderAction = new QAction(tr("Add Floder"), this);
	QAction* SettingAction = new QAction(tr("Setting"), this);
	QAction* HiddenAction = new QAction(tr("Hidden"), this);
	QAction* AboutAction = new QAction(tr("About"), this);
	QAction* deleteAction = new QAction(tr("Exit"), this);
	deleteAction->setObjectName("done");
	menu->addAction(OpenAction);
	menu->addAction(OpenAudioCDAction);
	menu->addSeparator();
	menu->addAction(AddFilesAction);
	menu->addAction(AddFloderAction);
	menu->addSeparator();
	menu->addAction(SettingAction);
	menu->exec(cur.pos());
}








