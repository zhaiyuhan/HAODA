#include "stdafx.h"
#include "PlayerView.h"
using namespace QtAV;
PlayerView::PlayerView(QWidget *parent)
	: BaseView(parent)

{
	_init_view(1024, 768, QColor(255, 255, 255, 100), false, true, true);
	m_unit = 1000;
	m_player = new AVPlayer(this);
	QVBoxLayout* vl = new QVBoxLayout();
	setLayout(vl);
	vl->setContentsMargins(0,0,0,0);
	m_vo = new VideoOutput(this);
	if (!m_vo->widget()) {
		QMessageBox::warning(nullptr, QString::fromLatin1("QtAV error"), tr("Can not create video renderer"));
		return;
	}
	m_player->setRenderer(m_vo);
	vl->addWidget(m_vo->widget());
	m_slider = new QSlider(this);
	m_slider->hide();
	/*m_slider->setOrientation(Qt::Horizontal);
	connect(m_slider, SIGNAL(sliderMoved(int)), SLOT(seekBySlider(int)));
	connect(m_slider, SIGNAL(sliderPressed()), SLOT(seekBySlider()));
	connect(m_player, SIGNAL(positionChanged(qint64)), SLOT(updateSlider(qint64)));
	connect(m_player, SIGNAL(started()), SLOT(updateSlider()));
	connect(m_player, SIGNAL(notifyIntervalChanged()), SLOT(updateSliderUnit()));

	vl->addWidget(m_slider);*/
	
	this->setLayout(vl);
}

PlayerView::~PlayerView()
{
}
void PlayerView::contextMenuEvent(QContextMenuEvent*)
{
	QCursor cur = this->cursor();
	menu = new Menu(this);
	//Menu HAODA
	Menu* HAODAMenu = new Menu(tr("HAO DA"), this);
	menu->addMenu(HAODAMenu);
	QAction* AboutHAODAAction = new QAction(tr("About HAODA"), this);
	HAODAMenu->addAction(AboutHAODAAction);
	HAODAMenu->addSeparator();
	QAction* PreferenceAction = new QAction(tr("Preference"), this);
	HAODAMenu->addAction(PreferenceAction);
	HAODAMenu->addSeparator();
	QAction* ExitAction = new QAction(tr("Exit"), this);
	HAODAMenu->addAction(ExitAction);
	connect(ExitAction, &QAction::triggered, this, [=]() { qApp->exit(); });
	//Menu File
	Menu* FileMenu = new Menu(tr("File"), this);
	menu->addMenu(FileMenu);
	QAction* OpenFileAction = new QAction(tr("Open"), this);
	FileMenu->addAction(OpenFileAction);
	connect(OpenFileAction, &QAction::triggered, this, [=]() {openFile(); });
	QAction* OpenUrlAction = new QAction(tr("Open Url"), this);
	FileMenu->addAction(OpenUrlAction);
	FileMenu->addSeparator();
	QAction* OpenFileActionX = new QAction(tr("Open in new Window"), this);
	FileMenu->addAction(OpenFileActionX);
	connect(OpenFileAction, &QAction::triggered, this, [=]() {openFile(); });
	QAction* OpenUrlActionX = new QAction(tr("Open Url in new Window"), this);
	FileMenu->addAction(OpenUrlActionX);
	FileMenu->addSeparator();
	QAction* CloseFileAction = new QAction(tr("Close"), this);
	FileMenu->addAction(CloseFileAction);
	//Menu Edit
	Menu* EditMenu = new Menu(tr("Eidt"), this);
	menu->addMenu(EditMenu);
	QAction* CopyFileToAction = new QAction(tr("Copy file to"), this);
	EditMenu->addAction(CopyFileToAction);
	QAction* ExportInformationAction = new QAction(tr("Export Information"), this);
	EditMenu->addAction(ExportInformationAction);
	//Menu Play Control
	Menu* PlayControlMenu = new Menu(tr("Play Control"), this);
	menu->addMenu(PlayControlMenu);
	QAction* PlayControlAction = new QAction(tr("Play/Pause"), this);
	PlayControlMenu->addAction(PlayControlAction);
	QAction* SpeedAction = new QAction(tr("Speed"), this);
	PlayControlMenu->addAction(SpeedAction);
	PlayControlMenu->addSeparator();
	QAction* ScreenshotsAction = new QAction(tr("Screen Shot"), this);
	PlayControlMenu->addAction(ScreenshotsAction);
	QAction* GoToScreenshotsAction = new QAction(tr("Find Screen Shot"), this);
	PlayControlMenu->addAction(GoToScreenshotsAction);
	//Menu Video
	Menu* VideoMenu = new Menu(tr("Video"), this);
	menu->addMenu(VideoMenu);
	QAction* DecoderAction = new QAction(tr("Decoder"), this);
	VideoMenu->addAction(DecoderAction);
	QAction* RenderAction = new QAction(tr("Render"), this);
	VideoMenu->addAction(RenderAction);
	QAction* AspectRatioAction = new QAction(tr("Aspect ratio"), this);
	VideoMenu->addAction(AspectRatioAction);
	QAction* ColorSpaceAction = new QAction(tr("Color space"), this);
	VideoMenu->addAction(ColorSpaceAction);
	//Menu Audio
	Menu* AudioMenu = new Menu(tr("Audio"), this);
	menu->addMenu(AudioMenu);
	
	//Menu Fansub
	Menu* FansubMenu = new Menu(tr("Fansub"), this);
	menu->addMenu(FansubMenu);

	//Menu View
	Menu* ViewMenu = new Menu(tr("View"), this);
	menu->addMenu(ViewMenu);
	QAction* MinimizeAction = new QAction(tr("Minimize"), this);
	ViewMenu->addAction(MinimizeAction);
	connect(MinimizeAction, &QAction::triggered, this, [=]() { showMinimized(); });
	QAction* FullScreenAction = new QAction(tr("Full Screen"), this);
	ViewMenu->addAction(FullScreenAction);
	connect(FullScreenAction, &QAction::triggered, this, [=]() { showFullScreen(); });
	QAction* MoveToMiddleAction = new QAction(tr("Move to middle"), this);
	ViewMenu->addAction(MoveToMiddleAction);
	connect(MoveToMiddleAction, &QAction::triggered, this, [=]() {
		QDesktopWidget* deskdop = QApplication::desktop();
		move((deskdop->width() - this->width()) / 2, (deskdop->height() - this->height()) / 2);
	});
	QAction* StayOnTopAction = new QAction(tr("Stay on Top"), this);
	ViewMenu->addAction(StayOnTopAction);
	connect(StayOnTopAction, &QAction::triggered, this, [=]() {  });
	QAction* HelpAction = new QAction(tr("Help"), this);
	menu->addSeparator();
	menu->addAction(HelpAction);
	menu->exec(cur.pos());
}
void PlayerView::_init_player()
{
	m_player = new AVPlayer(this);
	VideoRenderer* vo = VideoRenderer::create((VideoRendererId)property("rendererId").toInt());
	if (!vo || !vo->isAvailable() || !vo->widget())
	{
		QMessageBox::critical(0, QString::fromLatin1("HAODA"), tr("There's something wrong"));
		//i will improve here some day
	}
	m_player->setRenderer(vo);
}
void PlayerView::play(const QString& _filename)
{
	mFile = _filename;
	mTitle = mFile;
	if (!mFile.contains(QLatin1String("://")) || mFile.startsWith(QLatin1String("file://")))
	{
		mTitle = QFileInfo(mFile).fileName();
	}
	//you will set the window title here
	m_player->stop();
	m_player->play(_filename);
}
void PlayerView::play(const QUrl& _url)
{
}
void PlayerView::openFile()
{
	QString file = QFileDialog::getOpenFileName(nullptr, tr("Open file"));
	if (file.isEmpty())
		return;
	play(file);
}

void PlayerView::seekBySlider(int value)
{
	if (!m_player->isPlaying())
		return;
	m_player->seek(qint64(value * m_unit));
}

void PlayerView::seekBySlider()
{
	seekBySlider(m_slider->value());
}

void PlayerView::playPause()
{
	if (!m_player->isPlaying()) {
		m_player->play();
		return;
	}
	m_player->pause(!m_player->isPaused());
}

void PlayerView::updateSlider(qint64 value)
{
	m_slider->setRange(0, int(m_player->duration() / m_unit));
	m_slider->setValue(int(value / m_unit));
}

void PlayerView::updateSlider()
{
	updateSlider(m_player->position());
}

void PlayerView::updateSliderUnit()
{
	m_unit = m_player->notifyInterval();
	updateSlider();
}