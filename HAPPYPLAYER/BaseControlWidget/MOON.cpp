#include "stdafx.h"
#include "MOON.h"

MOON::MOON(QWidget *parent)
	: QWidget(parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::Popup | Qt::NoDropShadowWindowHint);
	this->setMaximumSize(100, 50);
	QPalette p = palette();
	p.setColor(QPalette::Background, QColor(0, 0, 0, 60));
	this->setPalette(p);
	
}

MOON::~MOON()
{
}


