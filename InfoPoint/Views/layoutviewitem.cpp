#include "layoutviewitem.h"

LayoutViewItem::LayoutViewItem(LocaleItems *it, QWidget *parent):

    listItem(it),
    descrizione(new QTextEdit(parent)),
    indirizzo(new QTextEdit(parent)),
    citta(new QTextEdit(parent)),
    nome(new QTextEdit(parent)),
    loc(it->getItemAddress()),
    closeButton(new QPushButton("Chiudi",parent)),
    saveModifica(new QPushButton("Salva modifiche",parent))


{
    QVBoxLayout* mainLayout=new QVBoxLayout();

    nome->setText(QString::fromStdString(loc->getNome()));
    mainLayout->addWidget(new QLabel("Nome: "));
    mainLayout->addWidget(nome);

    citta->setText(QString::fromStdString(loc->getCitta()));
    mainLayout->addWidget(new QLabel("Città: "));
    mainLayout->addWidget(citta);

    indirizzo->setText(QString::fromStdString(loc->getIndirizzo()));
    mainLayout->addWidget(new QLabel("Indirizzo: "));
    mainLayout->addWidget(indirizzo);

    descrizione->setText(QString::fromStdString(loc->getDescrizione()));
    mainLayout->addWidget(new QLabel("Descrizione: "));
    mainLayout->addWidget(descrizione);

    QHBoxLayout* btnLayout= new QHBoxLayout();
    btnLayout->addWidget(saveModifica);
    btnLayout->addWidget(closeButton);
    mainLayout->addLayout(btnLayout);
    setLayout(mainLayout);
    setModal(true);


     setFont(QFont("Times",10,3));
     connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));
     connect(saveModifica,SIGNAL(clicked()),this,SLOT(slotSaveModifica()));
     connect(saveModifica,SIGNAL(clicked()), this,SLOT(close()));

}

void LayoutViewItem::slotSaveModifica() const
{
    loc->setDescrizione(descrizione->toPlainText().toStdString());
    loc->setIndirizzo(indirizzo->toPlainText().toStdString());
    loc->setCitta(citta->toPlainText().toStdString());
    loc->setnome(nome->toPlainText().toStdString());
    listItem->update();

}
