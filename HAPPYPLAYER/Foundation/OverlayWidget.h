#pragma once

#include <QWidget>
#include <QtCore\qglobal.h>
#include <QEvent>
class OverlayWidget : public QWidget
{
	Q_OBJECT

public:
	explicit OverlayWidget(QWidget *parent = nullptr);
	~OverlayWidget();

protected:
	bool event(QEvent* event) Q_DECL_OVERRIDE;
	bool eventFilter(QObject* obj, QEvent* event) Q_DECL_OVERRIDE;
	virtual QRect overlayGeometry() const;

private:
	Q_DISABLE_COPY(OverlayWidget)

};
