#pragma once

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
	Menu* menu;
	QSlider* m_slider;
	int m_unit;
};
