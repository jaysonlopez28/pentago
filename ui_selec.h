/********************************************************************************
** Form generated from reading ui file 'selec.ui'
**
** Created: Sun 15. Feb 15:45:23 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SELEC_H
#define UI_SELEC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Selec
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *tp;
    QSpinBox *tssp;
    QSpinBox *ll;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *j1;
    QComboBox *j2;
    QPushButton *okButton;

    void setupUi(QDialog *Selec)
    {
    if (Selec->objectName().isEmpty())
        Selec->setObjectName(QString::fromUtf8("Selec"));
    Selec->resize(222, 212);
    formLayoutWidget = new QWidget(Selec);
    formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
    formLayoutWidget->setGeometry(QRect(40, 30, 170, 146));
    formLayout = new QFormLayout(formLayoutWidget);
    formLayout->setObjectName(QString::fromUtf8("formLayout"));
    formLayout->setContentsMargins(0, 0, 0, 0);
    label = new QLabel(formLayoutWidget);
    label->setObjectName(QString::fromUtf8("label"));

    formLayout->setWidget(0, QFormLayout::LabelRole, label);

    label_2 = new QLabel(formLayoutWidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

    label_3 = new QLabel(formLayoutWidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

    tp = new QSpinBox(formLayoutWidget);
    tp->setObjectName(QString::fromUtf8("tp"));
    tp->setMinimum(2);
    tp->setMaximum(4);

    formLayout->setWidget(0, QFormLayout::FieldRole, tp);

    tssp = new QSpinBox(formLayoutWidget);
    tssp->setObjectName(QString::fromUtf8("tssp"));
    tssp->setMinimum(3);
    tssp->setMaximum(9);

    formLayout->setWidget(1, QFormLayout::FieldRole, tssp);

    ll = new QSpinBox(formLayoutWidget);
    ll->setObjectName(QString::fromUtf8("ll"));
    ll->setMinimum(2);
    ll->setMaximum(42);
    ll->setValue(5);

    formLayout->setWidget(2, QFormLayout::FieldRole, ll);

    label_4 = new QLabel(formLayoutWidget);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

    label_5 = new QLabel(formLayoutWidget);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

    j1 = new QComboBox(formLayoutWidget);
    j1->setObjectName(QString::fromUtf8("j1"));

    formLayout->setWidget(3, QFormLayout::FieldRole, j1);

    j2 = new QComboBox(formLayoutWidget);
    j2->setObjectName(QString::fromUtf8("j2"));

    formLayout->setWidget(4, QFormLayout::FieldRole, j2);

    okButton = new QPushButton(Selec);
    okButton->setObjectName(QString::fromUtf8("okButton"));
    okButton->setGeometry(QRect(130, 180, 80, 24));

    retranslateUi(Selec);

    QMetaObject::connectSlotsByName(Selec);
    } // setupUi

    void retranslateUi(QDialog *Selec)
    {
    Selec->setWindowTitle(QApplication::translate("Selec", "Dialog", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Selec", "Taille plateau", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("Selec", "Taille sous plateau", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("Selec", "Longueur ligne", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("Selec", "Joueur 1 ", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("Selec", "Joueur 2 ", 0, QApplication::UnicodeUTF8));
    okButton->setText(QApplication::translate("Selec", "OK", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Selec);
    } // retranslateUi

};

namespace Ui {
    class Selec: public Ui_Selec {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELEC_H
