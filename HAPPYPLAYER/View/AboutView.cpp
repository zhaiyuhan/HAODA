#include "stdafx.h"
#include "AboutView.h"
#include "ui_AboutView.h"
#include "qtmaterialflatbutton.h"

AboutView::AboutView(QWidget *parent)
	: BaseView(parent)
{
	ui = new Ui::AboutView();
	ui->setupUi(this);
	setMaximumSize(640, 400);
	_init_view(640, 400, QColor(255, 255, 255, 100), true, true, true);
	setFixed(true);
	
	setAttribute(Qt::WA_DeleteOnClose);
	btnClose = new ButtonForTitleBar(this);
	btnClose->setType(CLOSE);
	btnClose->setFixedSize(QSize(18, 18));
	btnClose->setToolTip(tr("Close"));
	connect(btnClose, &QPushButton::clicked, this, [=]() {
		this->close();
		});
	m_mainButtonGroup = new QButtonGroup(this);
	m_mainButtonGroup->addButton(ui->btnW1, 0);
	m_mainButtonGroup->addButton(ui->btnW2, 1);
	m_mainButtonGroup->addButton(ui->btnW3, 2);
	m_mainButtonGroup->setExclusive(true);
	ui->btnW1->setChecked(true);
	CustomShadowEffect* bodyShadow = new CustomShadowEffect();
	bodyShadow->setBlurRadius(50.0);
	bodyShadow->setDistance(20.0);
	bodyShadow->setColor(QColor(0, 0, 0, 100));
	ui->AboutProgramtextBrowser->setGraphicsEffect(bodyShadow);
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	setGraphicsEffect(e);
	e->setOpacity(0.5);
	ui->AboutProgramtextBrowser->verticalScrollBar()->setGraphicsEffect(e);
	ui->AboutProgramtextBrowser->setOpenLinks(false);
	connect(ui->AboutProgramtextBrowser, &QTextBrowser::anchorClicked, this, [=](const QUrl& _url) {
		ShellExecuteA(NULL, "open", _url.toString().toStdString().c_str(), "","", SW_SHOW);
		});
	connect(m_mainButtonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked),
		[=](int id) { 
			switch (id)
			{
			case 0:
				ui->stackedWidget->setCurrentIndex(0);
				break;
			case 1:
				ui->stackedWidget->setCurrentIndex(1);
				break;
			case 2:
				ui->stackedWidget->setCurrentIndex(2);
				break;
			default:
				break;
			}
	});

	
}

AboutView::~AboutView()
{
	delete ui;
}
