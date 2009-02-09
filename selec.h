#ifndef SELEC_H
#define SELEC_H

#include <QtGui/QDialog>

namespace Ui {
    class Selec;
}

class Selec : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(Selec)
public:
    explicit Selec(int* _tp=2, int* _tssp=3, int* _l=5,int* _j1=0,int* _j2=0,QWidget *parent = 0);
    ~Selec();
    void updateInfo();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::Selec *m_ui;
    int* tp,*tssp,*l,*j1,*j2;

public slots:
    void modifMaxLigne(int i);

};

#endif // SELEC_H
