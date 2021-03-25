#include "searchlayout.h"


SearchLayout::SearchLayout(QWidget*p):
    QWidget(p),
    searchByNome(new QLineEdit(this)),
    searchByCitta(new QLineEdit(this)),


    boxNome(new QCheckBox("Nome",this)),
    boxCitta(new QCheckBox("Città",this)),
    boxTipo(new QCheckBox("Tipo",this)),
    searchByTipo(new CombTipoLocale(this)),
    listaLocali(new LocaleListWidget(this)),
    cerca(new QPushButton("Cerca",this)),
    resetta(new QPushButton("Resetta",this)),
    btnEliminaTrovato(new QPushButton("Elimina ricerca",this)),
    dimBott(QSize(120, 40))
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    QFormLayout* formSearch= new QFormLayout();

    searchByTipo->removeItem(0);


    searchByCitta->setEnabled(false);
    searchByNome->setEnabled(false);
    searchByTipo->setEnabled(false);



    formSearch->addRow(boxCitta,searchByCitta);
    formSearch->addRow(boxNome,searchByNome);
    formSearch->addRow(boxTipo,searchByTipo);


    mainLayout->addLayout(formSearch);
    mainLayout->addWidget(listaLocali);

    QHBoxLayout*HBlayout=new QHBoxLayout();
    HBlayout->addWidget(cerca);
    cerca->setFixedSize(dimBott);
    HBlayout->addWidget(resetta);
    resetta->setFixedSize(dimBott);
    HBlayout->addWidget(btnEliminaTrovato);
    btnEliminaTrovato->setFixedSize(dimBott);

    mainLayout->addLayout(HBlayout);
    connect(boxNome,SIGNAL(clicked(bool)),this,SLOT(slotDisableElements()));
    connect(boxCitta,SIGNAL(clicked(bool)),this,SLOT(slotDisableElements()));
    connect(boxTipo,SIGNAL(clicked(bool)),this,SLOT(slotDisableElements()));

}





void SearchLayout::slotDisableElements() const
{
    boxTipo->isChecked()?searchByTipo->setEnabled(true):searchByTipo->setEnabled(false);
    boxNome->isChecked()?searchByNome->setEnabled(true):searchByNome->setEnabled(false);
    boxCitta->isChecked()?searchByCitta->setEnabled(true):searchByCitta->setEnabled(false);
}



void SearchLayout::slotResetRicerca() const
{

    searchByCitta->clear();
    searchByCitta->clear();
    searchByTipo->setCurrentIndex(0);

    listaLocali->clear();
    listaLocali->update();
}




QLineEdit *SearchLayout::getSearchByNome() const
{
    return searchByNome;
}

QLineEdit *SearchLayout::getSearchByCitta() const
{
    return searchByCitta;
}

CombTipoLocale *SearchLayout::getSearchByTipo() const
{
    return searchByTipo;
}

QPushButton *SearchLayout::getCerca() const
{
    return cerca;
}

QPushButton *SearchLayout::getResetta() const
{
    return resetta;
}

LocaleListWidget *SearchLayout::getListaLocali() const
{
    return listaLocali;
}

QPushButton *SearchLayout::getBtnEliminaTrovato() const
{
    return btnEliminaTrovato;
}

QCheckBox *SearchLayout::getBoxNome() const
{
    return boxNome;
}

QCheckBox *SearchLayout::getBoxCitta() const
{
    return boxCitta;
}

QCheckBox *SearchLayout::getBoxTipo() const
{
    return boxTipo;
}
