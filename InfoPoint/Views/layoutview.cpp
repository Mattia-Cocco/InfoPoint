#include "layoutview.h"



LayoutView::LayoutView(QWidget *w):
    QWidget(w),
    buttonElimina(new QPushButton("Elimina",this)),
    btModifica(new QPushButton("Modifica",this)),
    listwidget(new LocaleListWidget(this)),
    dialog(nullptr),
    DimBott(QSize(120, 30))
{
    QVBoxLayout* VBox=new QVBoxLayout(this);
    buttonElimina->setEnabled(false);
    btModifica->setEnabled(false);

    listwidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    listwidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QLabel *labelListaLocali = new  QLabel(tr("I Locali presenti nel Container: "));
    labelListaLocali->setAlignment(Qt::AlignCenter);
    labelListaLocali->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#007c86;}");

    VBox->addWidget(labelListaLocali);
    VBox->addWidget(listwidget);

    QHBoxLayout*HBlayout=new QHBoxLayout();
    HBlayout->addWidget(buttonElimina);
    buttonElimina->setFixedSize(DimBott);
    HBlayout->addWidget(btModifica);
    btModifica->setFixedSize(DimBott);


    VBox->addLayout(HBlayout);
    connect(listwidget, SIGNAL(currentRowChanged(int)), this ,SLOT(slotElementSelected()));
    connect(this,SIGNAL(signalElementSelected(bool)),this, SLOT(slotElementSelected(bool)));
     listwidget->update();
}

LayoutView::~LayoutView()
{
    delete listwidget;
    delete buttonElimina;
}

LocaleListWidget *LayoutView::getListWidget() const
{
    return listwidget;
}

QPushButton *LayoutView::getBtnElimina() const
{

    return buttonElimina;
}

QPushButton *LayoutView::getBtnModifica() const
{
    return btModifica;
}



void LayoutView::slotElementSelected(bool b) const
{
    buttonElimina->setEnabled(b);
    btModifica->setEnabled(b);

}
void LayoutView::slotRChanged() const
{
    emit slotElementSelected(true);
}
