#include"controller.h"


Controller::Controller(Model *m, QWidget *parent):
    QWidget (parent),
    menuBar(new mainMenu(this)),model(m),
    mainLayout(new QHBoxLayout(this)),
    viewLayout(new LayoutView(this)),
    ricercaLayout(new SearchLayout(this)),
    addLayoutView(new insertLayout(this)) ,
    dialog(nullptr)

{

   mainLayout->setMenuBar(menuBar);
   mainLayout->addWidget(viewLayout);
   mainLayout->addWidget(ricercaLayout);
   mainLayout->addWidget(addLayoutView);

   slotViewInserisci();

   setLayout(mainLayout);

   connect(viewLayout->getBtnElimina(),SIGNAL(clicked()),this,SLOT(slotDeleteElement()));
   connect(addLayoutView->getBtConfirme(),SIGNAL(clicked()), this, SLOT(slotAddElement()));
   connect(menuBar->getSave(),SIGNAL(triggered()), this, SLOT(slotSaveData()));

   connect(viewLayout->getBtnModifica(),SIGNAL(clicked()),this,SLOT(slotViewModifica()));
   connect(viewLayout->getListWidget(),SIGNAL(signalDeleteFromList(Locale*)),this,SLOT(slotDeleteFromModel(Locale*)));

   connect(ricercaLayout->getCerca(),SIGNAL(clicked()),this,SLOT(slotRicerca()));
   connect(ricercaLayout->getBtnEliminaTrovato(),SIGNAL(clicked()),this, SLOT(slotDeleteFromModel()));
   connect(ricercaLayout->getResetta(),SIGNAL(clicked()), ricercaLayout, SLOT(slotResetRicerca()));
   slotLoad();
}

Controller::~Controller()
{
    model->save();

}

void Controller::slotViewRicerca() const
{
    viewLayout->hide();
    ricercaLayout->show();
    addLayoutView->hide();
}

Model* Controller::getModel() {
    return model;
}

void Controller::slotViewInserisci() const
{

     viewLayout->show();
     ricercaLayout->hide();
     addLayoutView->show();
}


void Controller::slotViewVisualizza()const
{
    viewLayout->show();
    ricercaLayout->hide();
    addLayoutView->hide();
}

void Controller::slotResetRicerca()const
{
    model->resetSearch();
}


void Controller::slotSaveData()const
{
   
  model->save();
  slotDataChanged(false);
}

void Controller::slotDataChanged(bool b) const
{
    menuBar->getSave()->setEnabled(b);
}

void Controller::slotLoad()
{

    QString file= QFileDialog::getOpenFileName(
                this,tr("Choose file"),
                "../InfoPoint/dati.xml",
                "File XML(*.xml)"
                );

               if(file!=""){
                   viewLayout->getListWidget()->clear();

                   model->clear();

                   model->setNewPath(file.toStdString());
                   model->load();
                    if(model->getDataSize()== 0){
                    QMessageBox::warning(this,"Attenzione!","Il file è vuoto.");
            }
          else{
                 for(unsigned int i=0; i<model->getDataSize(); i++)
                    viewLayout->getListWidget()->aggiungiLocale(model->itemAtpos(i));

                  model->setDataSaved(true);
                  slotViewRicerca();
                  slotViewVisualizza();
                  slotDataChanged(false);
               }
        }

}


void Controller::slotRicerca()
{
    slotResetRicerca();
   ricercaLayout->getListaLocali()->clear();
    if(model->getDataSize()==0){
        QMessageBox::warning(this, "Attenzione!","Non sono presenti elementi nel modello per poter fare la ricerca.");
    }else {
        if(ricercaLayout->getBoxTipo()->isChecked())
           model->searchType(ricercaLayout->getSearchByTipo()->currentText().toStdString());
        if(ricercaLayout->getBoxNome()->isChecked())
            model-> searchName( ricercaLayout->getSearchByNome()->text().toStdString());
        if(ricercaLayout->getBoxCitta()->isChecked()){

            model-> searchCitta( ricercaLayout->getSearchByCitta()->text().toStdString());
        }
        if(model->getResSize()==0){
               QMessageBox::warning(this, "Informazione",
                                    "Nessun elemento trovato, riprova.");
        }else {
            for(auto it = model->res_cbegin(); it != model->res_cend(); ++it)
                ricercaLayout->getListaLocali()->aggiungiLocale(*it);
        }

    }
}


void Controller::slotViewSegnalaBug()
{
    QMessageBox::about(this, "Report","se ci sono errori/bug potete contattarci all'indirizzo email: hossain.safdari@studenti.unipd.it oppure mattia.cocco@studenti.unipd.it, grazie!");
}

void Controller::slotDeleteElement()const
{
    if(viewLayout->getListWidget()->count() && viewLayout->getListWidget()->currItems()!= nullptr){
        LocaleItems* item = viewLayout->getListWidget()->getItems(viewLayout->getListWidget()->currentRow());
        model->erase(item->getItemAddress());
        delete item;
        viewLayout->getListWidget()->reset();
        slotDataChanged(true);
    }
    else {
        QMessageBox::information(viewLayout, "Errore", "Nessun elemento da eliminare selezionato!");
    }

}




void Controller::slotAddElement()
{
    if(!addLayoutView->getNome()->text().isEmpty() && ! addLayoutView->getDescrizione()->document()->isEmpty() && !addLayoutView->getCitta()->text().isEmpty()
            && !addLayoutView->getIndirizzo()->text().isEmpty() && addLayoutView->getTipoLocale()->currentIndex()>0)
    {
                int  indexType = addLayoutView->getTipoLocale()->currentIndex();
                string pushRating = addLayoutView->getqlRating()->text().toStdString();
                string pushApertura = addLayoutView->getApertura()->text().toStdString();
                string pushChiusura = addLayoutView->getChiusura()->text().toStdString();
                string push_nome = addLayoutView->getNome()->text().toStdString();
                string pushCitta = addLayoutView->getCitta()->text().toStdString();
                string  pushDescrizione = addLayoutView->getDescrizione()->toPlainText().toStdString();
                string  pushIndirizzo = addLayoutView->getIndirizzo()->text().toStdString();

                Locale* toPush=nullptr;
                switch (indexType) {
                    case 1:
                        toPush = new Bar(pushRating,pushApertura,pushChiusura,push_nome,pushCitta,pushDescrizione,pushIndirizzo,addLayoutView->getPostiaSedere()->isChecked());
                        break;
                    case 2:
                        toPush = new Ristorante(pushRating,pushApertura,pushChiusura,push_nome,pushCitta,pushDescrizione,pushIndirizzo,addLayoutView->getPagaCoperto()->isChecked());
                        break;
                    case 3:
                        toPush = new Pasticceria(pushRating,pushApertura,pushChiusura,push_nome,pushCitta,pushDescrizione,pushIndirizzo, addLayoutView->getSpecial()->text().toStdString(), addLayoutView->getcoffe()->isChecked());
                    break;
                    case 4:
                        toPush = new Discoteca(pushRating,pushApertura,pushChiusura,push_nome,pushCitta,pushDescrizione,pushIndirizzo,addLayoutView->getPagaIngresso()->isChecked(), addLayoutView->getPIngresso()->text().toUInt());
                    break;
                    case 5:
                        toPush= new Discobar(pushRating,pushApertura,pushChiusura,push_nome,pushCitta,pushDescrizione,pushIndirizzo, addLayoutView->getPostiaSedere()->isChecked(), addLayoutView->getPagaIngresso()->isChecked(), addLayoutView->getPIngresso()->text().toUInt(), addLayoutView->getInsertPrezzoDrink()->text().toStdString());
                    break;
                }

                if(toPush!= nullptr){
                    model->push_end(toPush);
                    viewLayout->getListWidget()->aggiungiLocale(toPush);
                    slotDataChanged(true);
                    QMessageBox::information(this,"Conferma", "Il locale è stato inserito con successo!");
                    setStyleSheet("QMessageBox{ color:#007c86;font-weight:bold;}");
                }
    }
    else{
        QMessageBox::information(this,"Errore", "Compila tutti i campi!");
        setStyleSheet("QMessageBox{ color:#007c86;font-weight:bold;}");

    }
}

void Controller::slotViewModifica()
{
    LocaleItems* a=viewLayout->getListWidget()->currItems();

    if(a==nullptr)
        QMessageBox::information(this,"Errore", "Nessun elemento da modificare selezionato!");
    else {
        if(dialog!=nullptr)
            delete dialog;
        dialog= new LayoutViewItem(a,this);
        dialog->show();
        slotDataChanged(true);
    }

}



void Controller::slotDeleteFromModel(Locale *loc) const
{

    model->erase(loc);
    delete  loc;
    ricercaLayout->slotResetRicerca();
    slotDataChanged(true);

}

void Controller::slotDeleteFromModel() const
{
    for(; ricercaLayout->getListaLocali()->count()!=0;){
        LocaleItems* itemSearch= ricercaLayout->getListaLocali()->getItems(0);
        LocaleItems* itemView=viewLayout->getListWidget()->getItems(itemSearch->getItemAddress());
        delete  itemSearch;
        delete  itemView;
    }
    model->deleteElemetiTrovati();
    slotDataChanged(true);
}




