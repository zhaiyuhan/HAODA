#include <BaseView.h>
#include <QtAV/QtAV.h>
#include <QtAVWidgets/QtAVWidgets.h>
#include "Menu.h"
#include <qtmaterialiconbutton.h>
#include <qtmaterialslider.h>


class PlayerView : public BaseView
{
	Q_OBJECT

public:
	explicit PlayerView(QWidget *parent = Q_NULLPTR);
	~PlayerView();
	bool setRenderer(QtAV::VideoRenderer* renderer) 
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
		if (m_renderer)
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
		return true;
}
protected:
	void contextMenuEvent(QContextMenuEvent*);
	void resizeEvent(QResizeEvent* event)
	{
		Q_UNUSED(event);
		m_PlayButton->resize(40, 40);
		m_PlayButton->move(event->size().width() / 2 - 15, event->size().height() - 120);
		sliderPos->resize(event->size().width() - 300, 25);
		sliderPos->move(150, event->size().height() - 40);
	}
signals:
	void ready();
public Q_SLOTS:
	void play(const QString& _filename);//play from the local file
	void play(const QUrl& _url);//play from the internet
	void openFile();
	void seekBySlider(int value);
	void seekBySlider();
	void playPause();
private Q_SLOTS:
	void setupUI();
	void _init_player();
	void tooglePlayPause();
	void updateSlider(qint64 value);
	void updateSlider();
	void updateSliderUnit();
private:
	//here are the play controller needs
	QtMaterialIconButton* m_PlayButton;
	QtMaterialSlider* const sliderPos;

	
private:
	int m_unit;
	QString mFile, mTitle;
	QtAV::VideoOutput* m_vo;
	QtAV::AVPlayer* m_player;
	QtAV::VideoRenderer* m_renderer;
	Menu* menu;
	QSlider* m_slider;
	


};
