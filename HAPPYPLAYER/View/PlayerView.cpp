#include "stdafx.h"
#include "PlayerView.h"
using namespace QtAV;
PlayerView::PlayerView(QWidget *parent)
	: BaseView(parent),
	PosSlider(new QtMaterialSlider),
	VolumeSlider(new QtMaterialSlider)
{
	_init_view(1024, 768, QColor(255, 255, 255, 100), false, true, true);
	//_init_TitleBar()
	m_unit = 1000;
	setupUI();
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

	_init_ui();
	_init_events();
}

PlayerView::~PlayerView()
{
}
void PlayerView::setupUI()
{
	
	QTimer::singleShot(0, this, SLOT(_init_player));
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
void PlayerView::_init_ui()
{
	m_VolumeButton = new QtMaterialIconButton(QIcon(":/Resources/volume.svg"), this);
	m_VolumeButton->setIconSize(QSize(20, 20));
	m_VolumeButton->setColor(QColor("#ffffff"));
	m_VolumeButton->setToolTip(tr("Mute"));
	m_PlayButton = new QtMaterialIconButton(QIcon(":/Resources/play.svg"), this);
	m_PlayButton->setIconSize(QSize(40, 40));
	m_PlayButton->setColor(QColor("#ffffff"));
	m_PlayButton->setToolTip(tr("Play/Pause"));
	//qDebug() << QIcon(":/play.svg:/Resources/pl ay.svg").isNull();
	m_ListButton = new QtMaterialIconButton(QIcon(":/Resources/list.svg"), this);
	m_ListButton->setIconSize(QSize(20, 20));
	m_ListButton->setColor(QColor("#ffffff"));
	m_ListButton->setToolTip(tr("Play List"));
	PosSlider->setThumbColor(QColor("#cecece"));//0f7ffa
	PosSlider->setParent(this);
	VolumeSlider->setThumbColor(QColor("#0f7ffa"));//0f7ffa
	VolumeSlider->setParent(this);
	m_CurrentTimeLabel = new QLabel(this);
	m_CurrentTimeLabel->setStyleSheet(QString("color:white"));
	m_CurrentTimeLabel->setToolTip(tr("Current Time"));
	m_CurrentTimeLabel->setText(QString::fromLatin1("00:00:00"));
	m_CurrentTimeLabel->setContentsMargins(2, 2, 2, 2);
	m_TotalTimeLabel = new QLabel(this);
	m_TotalTimeLabel->setStyleSheet(QString("color:white"));
	m_TotalTimeLabel->setToolTip(tr("Total Time"));
	m_TotalTimeLabel->setText(QString::fromLatin1("00:00:00"));
	m_TitleLabel = new QLabel(this);

	m_TitleLabel->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
	m_TitleLabel->setText(QString::fromLatin1("HAO DA"));
	m_TitleLabel->setStyleSheet(QString("font-family: 'Microsoft YaHei'; font: 19pt;color:white"));
	m_TitleLabel->adjustSize();
	//every time we change the title,we must use this function
	const QSize buttonsize = QSize(18, 18);
	//here are add the window control button
	btnClose = new ButtonForTitleBar(this);
	btnClose->setType(CLOSE);
	btnClose->setFixedSize(buttonsize);
	btnClose->setToolTip(tr("Close"));

	btnMin = new ButtonForTitleBar(this);
	btnMin->setType(MIN);
	btnMin->setFixedSize(buttonsize);
	btnMin->setToolTip(tr("Minimized"));

	btnMax = new ButtonForTitleBar(this);
	btnMax->setType(FULLSCREEN);
	btnMax->setFixedSize(buttonsize);
	btnMax->setToolTip(tr("FullScreen"));
}
void PlayerView::_init_events()
{
	connect(btnClose, &QPushButton::clicked, this, [=]() {
		qApp->exit();
	});
	connect(btnMin, &QPushButton::clicked, this, [=]() {
		btnMin->parentWidget()->showMinimized();
	});
	connect(btnMax, &QPushButton::clicked, [=](){
		btnMax->parentWidget()->isFullScreen() ? btnMax->parentWidget()->showNormal() : btnMax->parentWidget()->showFullScreen();
		update();
	});
	connect(this, &BaseView::isHadFocuse, [=](bool had) {
		if (had) {
			btnClose->changeStatus(NORMAL);
			btnMin->changeStatus(NORMAL);
			btnMax->changeStatus(NORMAL);
			update();
		}
		else {
			btnClose->changeStatus(NOSTATUS);
			btnMin->changeStatus(NOSTATUS);
			btnMax->changeStatus(NOSTATUS);
			update();
		}
		});
	connect(this, &BaseView::togglebtnMax, [=](bool iftoggle) {
		btnMax->toggleResizeButton(iftoggle);
		if (iftoggle) {
			btnMax->setToolTip(tr("Restore"));
		}
		else {
			btnMax->setToolTip(tr("FullScreen"));
		}
		update();
		
		});
}
void PlayerView::_init_player()
{
	m_player = new AVPlayer(this);
	VideoRenderer* vo = VideoRenderer::create((VideoRendererId)property("rendererId").toInt());
	if (!vo || !vo->isAvailable() || !vo->widget())
	{
		QMessageBox::critical(Q_NULLPTR, QString::fromLatin1("HAODA"), tr("There's something wrong"));
		//i will improve here some day
	}
	setRenderer(vo);
}
void PlayerView::tooglePlayPause()
{
	if (m_player->isPlaying())
	{
		m_player->pause(!m_player->isPaused());
	}
	else {
		if (mFile.isEmpty())
			return;
		if (!m_player->isPlaying())
			play(mFile);
		else
			m_player->play();

	}
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