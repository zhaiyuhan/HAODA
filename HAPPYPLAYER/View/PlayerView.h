#include <BaseView.h>
#include <QtAV/QtAV.h>
#include <QtAVWidgets/QtAVWidgets.h>
#include "Menu.h"
#include <qtmaterialiconbutton.h>
#include <qtmaterialslider.h>

#include "View/AboutView.h"

class PlayerView : public BaseView
{
	Q_OBJECT

public:
	explicit PlayerView(QWidget *parent = Q_NULLPTR);
	~PlayerView();
	/*bool setRenderer(QtAV::VideoRenderer* renderer) 
	{
		if (!renderer)
			return false;
		if (!renderer->widget())
		{
			QMessageBox::warning(Q_NULLPTR, QString::fromLatin1("HAODA"), tr("Can not use this renderer"));
			return false;
		}
		renderer->widget()->setMouseTracking(true);
		m_player->setRenderer(renderer);
		QWidget* r = Q_NULLPTR;
		if (renderer)
			r = renderer->widget();//release the old renderer
		if (r)
		{
			//i will change the layout here 
			if (r->testAttribute(Qt::WA_DeleteOnClose))
			{
				r->close();
			}
			else {
				r->close();
				delete r;
			}r = Q_NULLPTR;
		}// next add the widget
		m_Renderer = renderer;
		vl->addWidget(renderer->widget());
		return true;
}*/
protected:
	void contextMenuEvent(QContextMenuEvent*);
	void resizeEvent(QResizeEvent* event)
	{
		Q_UNUSED(event);
		//here are make the layout rule for the window control buttons
		btnClose->move(LeftValue, TopValue);
		btnMin->move(LeftValue + btnClose->width() + SpacingValue, TopValue);
		btnMax->move(LeftValue + btnMin->width() + btnMax->width() + 2 * SpacingValue, TopValue);
		//here are make the layout rule for the player control buttons
		m_VolumeButton->resize(20, 20);
		m_VolumeButton->move(40, event->size().height() - 100);
		VolumeSlider->resize(140, 25);
		VolumeSlider->move(50, event->size().height() - 100);
		m_PlayButton->resize(40, 40);
		m_PlayButton->move(event->size().width() / 2 - 15, event->size().height() - 120);
		m_ListButton->resize(20, 20);
		m_ListButton->move(event->size().width() - 40, event->size().height() - 100);
		PosSlider->resize(event->size().width() - 300, 25);
		PosSlider->move(150, event->size().height() - 55);
		m_CurrentTimeLabel->move(50, event->size().height() - 60);
		m_TotalTimeLabel->move(event->size().width() - 120, event->size().height() - 60);
		m_TitleLabel->move(event->size().width() / 2 - (m_TitleLabel->width() / 2), 20);
	}
	void closeEvent(QCloseEvent* event)
	{
		Q_UNUSED(event);
		if (m_player)
			m_player->stop();
		qApp->quit();
	}
signals:
	void ready();
public Q_SLOTS:
	bool eventFilter(QObject* watched, QEvent* event)
	{
		if (watched == m_PlayButton)
		{
			if (event->type() == QEvent::MouseButtonPress)
			{
				QMouseEvent* mouseEvent = (QMouseEvent*)event;
				if (mouseEvent->buttons() & Qt::LeftButton)
				{
					togglePlayPause();
					qDebug() << m_player->isPlaying();
				}
			}
			else if (event->type() == QEvent::MouseButtonDblClick)
			{
				QMouseEvent* mouseEvent = (QMouseEvent*)event;
				if (mouseEvent->buttons() & Qt::LeftButton)
				{
					return 0;
				}
			}
		}
		return QWidget::eventFilter(watched, event);
	}
	void play(const QString& _filename);//play from the local file
	void play(const QUrl& _url);//play from the internet
	void openFile();
private Q_SLOTS:
	void _init_ui();
	void _init_events();
	void togglePlayPause();

	void onStartPlay();//when start play what we should do
	void onStopPlay();//when stop play what we should do
private:
	QVBoxLayout* vl;
	int SpacingValue = 10;
	int LeftValue = 30;
	int TopValue = 30;
	ButtonForTitleBar* btnMin;
	ButtonForTitleBar* btnMax;
	ButtonForTitleBar* btnClose;
	//here are the play controller needs
	QtMaterialSlider* const VolumeSlider;
	QtMaterialIconButton* m_VolumeButton;
	QtMaterialIconButton* m_PlayButton;
	QtMaterialIconButton* m_ListButton;
	QtMaterialSlider* const PosSlider;
	QLabel* m_CurrentTimeLabel, * m_TotalTimeLabel, * m_TitleLabel;
	
private:

	QString mFile, mTitle;
	QtAV::AVPlayer* m_player;
	QtAV::VideoOutput* m_vo;
	Menu* menu;
	


};
