#pragma once

#include <BaseView.h>
#include <QtAV/QtAV.h>
#include <QtAVWidgets/QtAVWidgets.h>
class PlayerView : public BaseView
{
	Q_OBJECT

public:
	explicit PlayerView(QWidget *parent = Q_NULLPTR);
	~PlayerView();
public Q_SLOTS:
	void openMedia();
	void seekBySlider(int value);
	void seekBySlider();
	void playPause();
private Q_SLOTS:
	void updateSlider(qint64 value);
	void updateSlider();
	void updateSliderUnit();

private:
	QtAV::VideoOutput* m_vo;
	QtAV::AVPlayer* m_player;
	QSlider* m_slider;
	QPushButton* m_openBtn;
	QPushButton* m_playBtn;
	QPushButton* m_stopBtn;
	int m_unit;
};
