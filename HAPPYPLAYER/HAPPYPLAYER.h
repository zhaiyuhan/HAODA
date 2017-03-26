#pragma once

#include <QtWidgets\QMainWindow>
#include "Foundation\WindowCompositionAttribute.h"
#include "Foundation\BaseView.h"
#include <qpalette.h>

class HAPPYPLAYER : public QMainWindow
{
	Q_OBJECT

public:
	explicit HAPPYPLAYER(QWidget *parent = Q_NULLPTR);

protected:
	void InitView();

	void EnableTransparentBackground(bool ifEnable);
	void EnableGaussianBlur(bool ifEnable);
	void EnableWindowShadow(bool ifEnable);
	void EnableAnimation(bool ifEnable);
	bool nativeEvent(const QByteArray &eventType, void *message, long *result);
private:

};
