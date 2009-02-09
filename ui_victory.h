/********************************************************************************
** Form generated from reading ui file 'victory.ui'
**
** Created: Fri 6. Feb 04:00:21 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_VICTORY_H
#define UI_VICTORY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Victory
{
public:
    QLabel *label;

    void setupUi(QDialog *Victory)
    {
    if (Victory->objectName().isEmpty())
        Victory->setObjectName(QString::fromUtf8("Victory"));
    Victory->resize(400, 300);
    label = new QLabel(Victory);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(90, 80, 161, 101));

    retranslateUi(Victory);

    QMetaObject::connectSlotsByName(Victory);
    } // setupUi

    void retranslateUi(QDialog *Victory)
    {
    Victory->setWindowTitle(QApplication::translate("Victory", "Dialog", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Victory", "Victoire !", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Victory);
    } // retranslateUi

};

namespace Ui {
    class Victory: public Ui_Victory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VICTORY_H
