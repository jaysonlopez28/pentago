#include "selec.h"
#include "ui_selec.h"

Selec::Selec(int* _tp , int * _tssp , int * _l,int* _j1,int* _j2 ,QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::Selec),
    tp(_tp),tssp(_tssp),l(_l),j1(_j1),j2(_j2)
{
    m_ui->setupUi(this);
    m_ui->j1->addItem(QString("Humain"),QVariant(0));
    m_ui->j1->addItem(QString("IA"),QVariant(1));
    m_ui->j2->addItem(QString("Humain"),QVariant(0));
    m_ui->j2->addItem(QString("IA"),QVariant(1));
    connect(m_ui->okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(m_ui->tp, SIGNAL(valueChanged(int)), this, SLOT(modifMaxLigne(int)));
    connect(m_ui->tssp, SIGNAL(valueChanged(int)), this, SLOT(modifMaxLigne(int)));

}

Selec::~Selec()
{
    delete m_ui;

}

void Selec::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Selec::modifMaxLigne(int i){
    int max = m_ui->tssp->value();
    max *= m_ui->tp->value();
    m_ui->ll->setMaximum(max);
    m_ui->ll->repaint();
}

void Selec::updateInfo(){

    (*j1)   = m_ui->j1->itemData(m_ui->j1->currentIndex ()).toInt();
    (*j2)   = m_ui->j2->itemData(m_ui->j2->currentIndex ()).toInt();
    (*tp)   = m_ui->tp->value();
    (*tssp) = m_ui->tssp->value();
    (*l)    = m_ui->ll->value();

}
