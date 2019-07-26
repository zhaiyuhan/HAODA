/********************************************************************************
** Form generated from reading UI file 'AboutView.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTVIEW_H
#define UI_ABOUTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "baseview.h"

QT_BEGIN_NAMESPACE

class Ui_AboutView
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnW1;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnW2;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnW3;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QTextBrowser *AboutProgramtextBrowser;
    QWidget *page2;
    QWidget *page3;
    QTextBrowser *textBrowser;

    void setupUi(BaseView *AboutView)
    {
        if (AboutView->objectName().isEmpty())
            AboutView->setObjectName(QString::fromUtf8("AboutView"));
        AboutView->resize(640, 400);
        AboutView->setMinimumSize(QSize(640, 400));
        AboutView->setMaximumSize(QSize(640, 400));
        AboutView->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: rgba(255, 255, 255, 0%);\n"
"  border: 1px solid;\n"
"  border-color: transparent;\n"
"\n"
"  border-radius: 5px;\n"
"  padding: 4px;\n"
"  color: rgb(27, 27, 27);\n"
"  \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  border-color: #396895;\n"
"  color: rgb(27, 27, 27);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"  background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4c98fe, stop: 1 #0564e3);\n"
"  border-top-color: #247fff;\n"
"  border-bottom-color: #003ddb;\n"
"  border-left-color: #125eed;\n"
"  border-right-color: #125eed;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"  color: #333333;\n"
"}\n"
"QPushButton:checked {\n"
"  color: rgba(255, 255, 255, 90%);\n"
"  background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4c98fe, stop: 1 #0564e3);\n"
"  border-top-color: #247fff;\n"
"  border-bottom-color: #003ddb;\n"
"  border-left-color: #125eed;\n"
"  border-right-color: #125eed;\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(AboutView);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label = new QLabel(AboutView);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(150, 120));
        label->setPixmap(QPixmap(QString::fromUtf8(":/logo150.png")));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(AboutView);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(27, 27, 27);\n"
"font: 25 16pt \"Microsoft YaHei UI\";"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(AboutView);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(9);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(99, 99, 99);"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnW1 = new QPushButton(AboutView);
        btnW1->setObjectName(QString::fromUtf8("btnW1"));
        btnW1->setMinimumSize(QSize(120, 0));
        btnW1->setMaximumSize(QSize(120, 16777215));
        btnW1->setCheckable(true);

        horizontalLayout_2->addWidget(btnW1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        btnW2 = new QPushButton(AboutView);
        btnW2->setObjectName(QString::fromUtf8("btnW2"));
        btnW2->setMinimumSize(QSize(120, 0));
        btnW2->setMaximumSize(QSize(120, 16777215));
        btnW2->setCheckable(true);

        horizontalLayout_3->addWidget(btnW2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        btnW3 = new QPushButton(AboutView);
        btnW3->setObjectName(QString::fromUtf8("btnW3"));
        btnW3->setMinimumSize(QSize(120, 0));
        btnW3->setMaximumSize(QSize(120, 16777215));
        btnW3->setCheckable(true);

        horizontalLayout_4->addWidget(btnW3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        stackedWidget = new QStackedWidget(AboutView);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(420, 0));
        stackedWidget->setMaximumSize(QSize(420, 16777215));
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        AboutProgramtextBrowser = new QTextBrowser(page1);
        AboutProgramtextBrowser->setObjectName(QString::fromUtf8("AboutProgramtextBrowser"));
        AboutProgramtextBrowser->setGeometry(QRect(10, 20, 391, 341));
        AboutProgramtextBrowser->setStyleSheet(QString::fromUtf8("QTextBrowser{font: 9pt \"Microsoft YaHei UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 1px solid;\n"
"border-color: transparent;\n"
"}\n"
"QScrollBar:vertical\n"
"{\n"
"    width:8px;\n"
"    background:rgba(0,0,0,0%);\n"
"    margin:0px,0px,0px,0px;\n"
"    padding-top:9px;\n"
"    padding-bottom:9px;\n"
"}\n"
"QScrollBar::handle:vertical\n"
"{\n"
"    width:8px;\n"
"    background:rgba(0,0,0,25%);\n"
"    border-radius:4px;\n"
"    min-height:20;\n"
"}\n"
"QScrollBar::handle:vertical:hover\n"
"{\n"
"    width:8px;\n"
"    background:rgba(0,0,0,50%);\n"
"    border-radius:4px;\n"
"    min-height:20;\n"
"}\n"
"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical\n"
"{\n"
"    background:rgba(0,0,0,10%);\n"
"    border-radius:4px;\n"
"}\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"    height:0px;width:0px;\n"
"    border-image:none;\n"
"    subcontrol-position:bottom;\n"
"}\n"
"QScrollBar::sub-line:vertical\n"
"{\n"
"    height:0px;width:0px;\n"
"    border-image:none;\n"
"    subcontrol"
                        "-position:top;\n"
"}\n"
"QScrollBar::add-line:vertical:hover\n"
"{\n"
"    height:0px;width:0px;\n"
"    border-image:none;\n"
"    subcontrol-position:bottom;\n"
"}\n"
"QScrollBar::sub-line:vertical:hover\n"
"{\n"
"    height:0px;width:0px;\n"
"    border-image:none;\n"
"    subcontrol-position:top;\n"
"}\n"
""));
        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName(QString::fromUtf8("page3"));
        textBrowser = new QTextBrowser(page3);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 411, 361));
        textBrowser->setStyleSheet(QString::fromUtf8("QTextBrowser{font: 9pt \"Microsoft YaHei UI\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 1px solid;\n"
"border-color: transparent;\n"
"}\n"
"QScrollBar:vertical\n"
"{\n"
"    width:8px;\n"
"    background:rgba(0,0,0,0%);\n"
"    margin:0px,0px,0px,0px;\n"
"    padding-top:9px;\n"
"    padding-bottom:9px;\n"
"}\n"
"QScrollBar::handle:vertical\n"
"{\n"
"    width:8px;\n"
"    background:rgba(0,0,0,25%);\n"
"    border-radius:4px;\n"
"    min-height:20;\n"
"}\n"
"QScrollBar::handle:vertical:hover\n"
"{\n"
"    width:8px;\n"
"    background:rgba(0,0,0,50%);\n"
"    border-radius:4px;\n"
"    min-height:20;\n"
"}\n"
"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical\n"
"{\n"
"    background:rgba(0,0,0,10%);\n"
"    border-radius:4px;\n"
"}\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"    height:0px;width:0px;\n"
"    border-image:none;\n"
"    subcontrol-position:bottom;\n"
"}\n"
"QScrollBar::sub-line:vertical\n"
"{\n"
"    height:0px;width:0px;\n"
"    border-image:none;\n"
"    subcontrol"
                        "-position:top;\n"
"}\n"
"QScrollBar::add-line:vertical:hover\n"
"{\n"
"    height:0px;width:0px;\n"
"    border-image:none;\n"
"    subcontrol-position:bottom;\n"
"}\n"
"QScrollBar::sub-line:vertical:hover\n"
"{\n"
"    height:0px;width:0px;\n"
"    border-image:none;\n"
"    subcontrol-position:top;\n"
"}\n"
""));
        stackedWidget->addWidget(page3);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(AboutView);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AboutView);
    } // setupUi

    void retranslateUi(BaseView *AboutView)
    {
        AboutView->setWindowTitle(QCoreApplication::translate("AboutView", "AboutView", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("AboutView", "HAODA", nullptr));
        label_3->setText(QCoreApplication::translate("AboutView", "Beta 1.0", nullptr));
        btnW1->setText(QCoreApplication::translate("AboutView", "\350\256\270\345\217\257\350\257\201", nullptr));
        btnW2->setText(QCoreApplication::translate("AboutView", "\345\217\202\344\270\216\350\200\205", nullptr));
        btnW3->setText(QCoreApplication::translate("AboutView", "\347\254\254\344\270\211\346\226\271\345\274\200\346\272\220\350\256\270\345\217\257", nullptr));
        AboutProgramtextBrowser->setHtml(QCoreApplication::translate("AboutView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:18pt; font-weight:600; color:#272727;\">HAODA</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:12pt; font-weight:600; color:#272727;\">A modern video player for Windows10.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font"
                        "-family:'SimSun'; font-size:11pt; font-weight:600; color:#272727;\">Copyright (C) 2019-2020 </span><a href=\"https://github.com/zhaiyuhan/HAODA\"><span style=\" font-family:'SimSun'; text-decoration: underline; color:#272727;\">ZhaiChangtui</span></a></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\">\346\234\254\347\250\213\345\272\217\344\270\272\350\207\252\347\224\261\350\275\257\344\273\266\357\274\214\345\234\250\350\207\252\347\224\261\350\275\257\344\273\266\350\201\224\347\233\237\345\217\221\345\270\203\347\232\204 GNU \351\200\232\347\224\250\345\205\254\345\205\261\350\256\270\345\217\257\345\215\217\350\256\256\347\232\204\347\272\246\346\235\237\344\270\213\357\274\214\344\275\240\345\217\257\344\273\245\345\257\271\345\205\266\350\277\233\350\241\214\345\206\215\345\217\221\345\270\203\345\217\212\344\277\256\346\224"
                        "\271\343\200\202\345\215\217\350\256\256\347\211\210\346\234\254\344\270\272\347\254\254\344\270\211\347\211\210\346\210\226\357\274\210\351\232\217\344\275\240\357\274\211\346\233\264\346\226\260\347\232\204\347\211\210\346\234\254\343\200\202</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\">\346\210\221\344\273\254\345\270\214\346\234\233\345\217\221\345\270\203\347\232\204\350\277\231\346\254\276\347\250\213\345\272\217\346\234\211\347\224\250\357\274\214\344\275\206\344\270\215\344\277\235\350\257\201\357\274\214\347\224\232\350\207\263\344\270\215\344\277\235\350\257\201\345\256\203\346\234\211\347\273\217\346\265\216\344\273\267\345\200\274\345\222\214\351\200\202\345\220\210\347\211\271\345\256\232\347\224\250\351\200\224\343\200\202\350\257\246\346\203\205\345\217\202\350\247\201 GNU \351\200\232\347\224\250\345\205"
                        "\254\345\205\261\350\256\270\345\217\257\345\215\217\350\256\256\343\200\202</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\">\344\275\240\347\220\206\345\275\223\345\267\262\346\224\266\345\210\260\344\270\200\344\273\275GNU\351\200\232\347\224\250\345\205\254\345\205\261\350\256\270\345\217\257\345\215\217\350\256\256\347\232\204\345\211\257\346\234\254\357\274\214\345\246\202\346\236\234\346\262\241\346\234\211\357\274\214\350\257\267\346\237\245\351\230\205&lt;</span><a href=\"http://www.gnu.org/licenses/\"><span style=\" font-family:'SimSun'; text-decoration: underline; color:#636363;\">http://www.gnu.org/licenses/</span></a><span style=\" font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\">&gt;\343\200\202</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margi"
                        "n-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\">This program is free software: you can redistribute it and/or modify</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\">it under the terms of the GNU General Public License as published by</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\">the Fr"
                        "ee Software Foundation, either version 3 of the License, or</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\">(at your option) any later version.</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\">This program is distributed in the hope that it will be useful,</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0;"
                        " text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\">but WITHOUT ANY WARRANTY; without even the implied warranty of</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\">MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\">See the GNU General Public License for more details.</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\"><br /></p>\n"
"<p "
                        "align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\">You should have received a copy of the GNU General Public License</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\">along with this program.  If not, see &lt;</span><a href=\"http://www.gnu.org/licenses/\"><span style=\" font-family:'SimSun'; text-decoration: underline; color:#63637d;\">http://www.gnu.org/licenses/</span></a><span style=\" font-family:'SimSun'; font-size:11pt; font-weight:600; color:#636363;\">&gt;</span></p></body></html>", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("AboutView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-weight:600;\">Qt</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-weight:600;\">QtAV</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">QtAV is a multimedia pl"
                        "ayback library based on Qt and FFmpeg. It can help you to write a player with less effort than ever before.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">QtAV has been added to FFmpeg projects pagehttp://ffmpeg.org/projects.html</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">QtAV is free software licensed under the term of LGPL v2.1. The player example is licensed under GPL v3. If you use QtAV or its constituent libraries, you must adhere to the terms of the license in question.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-weight:600;\">FFmpeg</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; co"
                        "lor:#000000;\">Copyright (C) 2019 Kyle Schwarz</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#000000;\">This program is free software: you can redistribute it and/or modify</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#000000;\">it under the terms of the GNU General Public License as published by</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#000000;\">the Free Software Foundation, either version 3 of the License, or</span></p>\n"
"<p style=\" margin-top:12px; m"
                        "argin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#000000;\">(at your option) any later version.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#000000;\">This program is distributed in the hope that it will be useful,</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#000000;\">but WITHOUT ANY WARRANTY; without even the implied warranty of</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'"
                        "; color:#000000;\">MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#000000;\">GNU General Public License for more details.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#000000;\">You should have received a copy of the GNU General Public License</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New'; color:#000000;\">along with this program. If not, see &lt;http://www.gnu.org/licenses/&gt;.</span></p>\n"
"<p style=\" mar"
                        "gin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-weight:600;\">Qt-material-widget</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">Copyright Johannes Hilden (c) 2017</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">All rights reserved.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p "
                        "style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">Redistribution and use in source and binary forms, with or without</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">modification, are permitted provided that the following conditions are met:</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">* Redistributions of source code must retain the above copyright</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'"
                        "SimSun';\">notice, this list of conditions and the following disclaimer.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">* Redistributions in binary form must reproduce the above</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">copyright notice, this list of conditions and the following</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">disclaimer in the documentation and/or other materials provided</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -q"
                        "t-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">with the distribution.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">* Neither the name of Author name here nor the names of other</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">contributors may be used to endorse or promote products derived</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">from this software without specific prior written permission.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margi"
                        "n-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">&quot;AS IS&quot; AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">A PARTICULAR PURPOSE ARE DISCLAIME"
                        "D. IN NO EVENT SHALL THE COPYRIGHT</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY</span><"
                        "/p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutView: public Ui_AboutView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTVIEW_H
