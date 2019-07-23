#include <BaseView.h>
#include <QtAV/QtAV.h>
#include <QtAVWidgets/QtAVWidgets.h>
#include "Menu.h"


class PlayerView : public BaseView
{
	Q_OBJECT

public:
	explicit PlayerView(QWidget *parent = Q_NULLPTR);
	~PlayerView();
protected:
	void contextMenuEvent(QContextMenuEvent*);
public Q_SLOTS:
	void play(const QString& _filename);//play from the local file
	void play(const QUrl& _url);//play from the internet
	void openFile();
	void seekBySlider(int value);
	void seekBySlider();
	void playPause();
private Q_SLOTS:
	void _init_player();
	void updateSlider(qint64 value);
	void updateSlider();
	void updateSliderUnit();

private:
	int m_unit;
	QString mFile, mTitle;
	QtAV::VideoOutput* m_vo;
	QtAV::AVPlayer* m_player;
	Menu* menu;
	QSlider* m_slider;
	


};
