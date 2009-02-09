/********************************************************************************
** Form generated from reading ui file 'popup.ui'
**
** Created: Fri 6. Feb 01:16:39 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_POPUP_H
#define UI_POPUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_6;
    QSpinBox *tp;
    QSpinBox *tssp;
    QSpinBox *tl;
    QComboBox *j1;
    QComboBox *j2;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(332, 204);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    formLayoutWidget = new QWidget(centralwidget);
    formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
    formLayoutWidget->setGeometry(QRect(30, 30, 189, 146));
    formLayout = new QFormLayout(formLayoutWidget);
    formLayout->setObjectName(QString::fromUtf8("formLayout"));
    formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    formLayout->setContentsMargins(0, 0, 0, 0);
    label_2 = new QLabel(formLayoutWidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

    label_3 = new QLabel(formLayoutWidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

    label_5 = new QLabel(formLayoutWidget);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

    label_4 = new QLabel(formLayoutWidget);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

    label_6 = new QLabel(formLayoutWidget);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

    tp = new QSpinBox(formLayoutWidget);
    tp->setObjectName(QString::fromUtf8("tp"));

    formLayout->setWidget(0, QFormLayout::FieldRole, tp);

    tssp = new QSpinBox(formLayoutWidget);
    tssp->setObjectName(QString::fromUtf8("tssp"));

    formLayout->setWidget(1, QFormLayout::FieldRole, tssp);

    tl = new QSpinBox(formLayoutWidget);
    tl->setObjectName(QString::fromUtf8("tl"));

    formLayout->setWidget(2, QFormLayout::FieldRole, tl);

    j1 = new QComboBox(formLayoutWidget);
    j1->setObjectName(QString::fromUtf8("j1"));

    formLayout->setWidget(3, QFormLayout::FieldRole, j1);

    j2 = new QComboBox(formLayoutWidget);
    j2->setObjectName(QString::fromUtf8("j2"));

    formLayout->setWidget(4, QFormLayout::FieldRole, j2);

    pushButton = new QPushButton(centralwidget);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(230, 140, 71, 31));
    MainWindow->setCentralWidget(centralwidget);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("MainWindow", "Taille plateau", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("MainWindow", "Taille sous-plateau", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("MainWindow", "Longueur ligne", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("MainWindow", "Joueur 1", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("MainWindow", "Joueur 2", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("MainWindow", "OK", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUP_H
