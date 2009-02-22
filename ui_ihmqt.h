/********************************************************************************
** Form generated from reading ui file 'ihmqt.ui'
**
** Created: Sun 15. Feb 15:45:23 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_IHMQT_H
#define UI_IHMQT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IhmQTClass
{
public:
    QWidget *centralWidget;
    QFrame *gridFrame_5;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IhmQTClass)
    {
    if (IhmQTClass->objectName().isEmpty())
        IhmQTClass->setObjectName(QString::fromUtf8("IhmQTClass"));
    IhmQTClass->resize(367, 448);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(IhmQTClass->sizePolicy().hasHeightForWidth());
    IhmQTClass->setSizePolicy(sizePolicy);
    IhmQTClass->setLayoutDirection(Qt::LeftToRight);
    centralWidget = new QWidget(IhmQTClass);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    gridFrame_5 = new QFrame(centralWidget);
    gridFrame_5->setObjectName(QString::fromUtf8("gridFrame_5"));
    gridFrame_5->setGeometry(QRect(20, 90, 321, 301));
    gridFrame_5->setStyleSheet(QString::fromUtf8("border-image: url(:/image/ressources/Plateau.png);"));
    gridLayout_5 = new QGridLayout(gridFrame_5);
    gridLayout_5->setSpacing(0);
    gridLayout_5->setMargin(0);
    gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
    label = new QLabel(centralWidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(50, 10, 261, 61));
    label->setStyleSheet(QString::fromUtf8("background-color: rgb(89, 100, 255);\n"
"font: 75 11pt \"Berlin Sans FB Demi\";"));
    IhmQTClass->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(IhmQTClass);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 367, 24));
    IhmQTClass->setMenuBar(menuBar);
    mainToolBar = new QToolBar(IhmQTClass);
    mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
    IhmQTClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(IhmQTClass);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    IhmQTClass->setStatusBar(statusBar);

    retranslateUi(IhmQTClass);

    QMetaObject::connectSlotsByName(IhmQTClass);
    } // setupUi

    void retranslateUi(QMainWindow *IhmQTClass)
    {
    IhmQTClass->setWindowTitle(QApplication::translate("IhmQTClass", "IhmQT", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("IhmQTClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Berlin Sans FB Demi'; font-size:11pt; font-weight:72; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Joueur</p></body></html>", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(IhmQTClass);
    } // retranslateUi

};

namespace Ui {
    class IhmQTClass: public Ui_IhmQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHMQT_H
