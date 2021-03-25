#include "model.h"
using std::cerr;
using std::endl;


void Model::push_end(Locale *l)
{
    lista_locali->push_back(l);
    if(!(*search==*lista_locali))
       *search=*lista_locali;
    dataSaved=false;
}



bool Model::isEmpty() const
{
    return lista_locali->empty();

}

void Model::clear()
{
    dataSaved=false;
    unsigned int i=0;
    while(i<lista_locali->getVsize()){
        delete lista_locali->atPos(i);
        lista_locali->clear();
        i++;
    }
}


void Model::resetSearch()const
{

    if(!(*search == *lista_locali))
        *search = *lista_locali;
}


void Model::deleteElemetiTrovati() const
{
    for(auto it = res_cbegin(); it != res_cend(); ++it){
        lista_locali->erase(*it);
        delete (*it);
    }
    resetSearch();
}





Locale *Model::itemAtpos(unsigned int i)
{
    dataSaved=false;
    return lista_locali->atPos(i);
}

Locale *Model::resItemAtpos(unsigned int i){
    return search->atPos(i);
}

Model::Model(std::string m):
dataSaved(true),
lista_locali(new Container<Locale*>(2)),
search(new Container<Locale*>(2)),path(m)
{}





Model::~Model(){
    for(unsigned int i=0; i<lista_locali->getVsize(); i++)
        delete lista_locali->atPos(i);
    delete search;
}


Container<Locale*>::iterator Model::begin()
{
    dataSaved=false;
    return lista_locali->begin();

}

Container<Locale*>::iterator Model::end()
{
    dataSaved=false;
    return lista_locali->end();
}

Container<Locale*>::const_iterator Model::cend() const
{
    return lista_locali->cend();
}

unsigned int Model::getDataSize() const
{
    return lista_locali->getVsize();
}

unsigned int Model::getDataCapacity() const
{
    return lista_locali->getVcapacity();
}

unsigned int Model::getResSize() const
{
    return search->getVsize();
}


void Model::searchName(std::string nome) const
{
    for(auto it=search->cbegin(); it!=search->cend(); it++){
        if(nome!=(*it)->getNome()){
            search->erase(*it);
            --it;
        }
    }
}


Container<Locale*>::const_iterator Model::cbegin() const
{
    return lista_locali->cbegin();
}



void Model::setNewPath(std::string s)
{
    path=s;
    delete lista_locali;
    dataSaved=false;
    lista_locali= new Container<Locale*>();

}


string Model::getPath() const
{
     return path;
}

bool Model::getDataSaved() const
{
    return dataSaved;
}

void Model::setDataSaved(bool s)
{
    dataSaved=s;
}

void Model::printAll() const
{
    lista_locali->printAll();
}


void Model::erase(unsigned int i)
{
    dataSaved=false;
    lista_locali->erase(i);
}

void Model::erase(unsigned int start, unsigned int end)
{
    dataSaved=false;
    lista_locali->erase(start,end);
}

void Model::erase(Locale *it)
{
    dataSaved=false;
    lista_locali->erase(it);
}

Container<Locale*>::const_iterator Model::res_cbegin() const
{
    return search->cbegin();
}

Container<Locale*>::const_iterator Model::res_cend() const
{
    return search->cend();
}



void Model::searchType(std::string tipo)const {
     for(auto it =res_cbegin() ; it != res_cend(); ++it){
        if(tipo != (*it)->getTipo()){
            search->erase(*it);
            --it;
        }
     }
}

void Model::searchCitta(std::string citta) const
{
    for(auto it=search->cbegin(); it!=search->cend(); it++){
        if(citta!=(*it)->getCitta()){
            search->erase(*it);
            --it;
        }
    }
}

void Model::save()
{
    QSaveFile file(QString::fromStdString(path));
    if(!file.open(QIODevice::WriteOnly)){
        throw FileException("Error");
    }

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeComment("Attenzione non modificare ");

    writer.writeStartElement("root");  //root

    auto iter=lista_locali->cbegin();
    while(iter!=lista_locali->cend()) {

        const Locale* toSave = *iter;
        const QString tipo=QString::fromStdString(toSave->getTipo());
        writer.writeEmptyElement(tipo);

        writer.writeAttribute("rating",QString::fromStdString(toSave->getRating()));
        writer.writeAttribute("oraApertura",QString::fromStdString(toSave->getOraApertura()));
        writer.writeAttribute("oraChiusura",QString::fromStdString(toSave->getOraChiusura()));
        writer.writeAttribute("nome",QString::fromStdString(toSave->getNome()));
        writer.writeAttribute("citta",QString::fromStdString(toSave->getCitta()));
        writer.writeAttribute("descrizione",QString::fromStdString(toSave->getDescrizione()));
        writer.writeAttribute("indirizzo",QString::fromStdString(toSave->getIndirizzo()));


        if(tipo=="Bar"){
                    const Bar* b= dynamic_cast<const Bar*>(toSave);
                    writer.writeAttribute("postiASedere",b->getPostiASedere()? "Si": "No");
                }

        if(tipo=="Ristorante"){
                    const Ristorante* r= dynamic_cast<const Ristorante*>(toSave);
                    writer.writeAttribute("coperto",r->getCoperto()? "Si":"No");
                }
        if(tipo=="Pasticceria"){
                    const Pasticceria* p= dynamic_cast<const Pasticceria*>(toSave);
                    writer.writeAttribute("specialita", QString::fromStdString(p->getSpecialita()));
                    writer.writeAttribute("caffetteria", p->getCaffetteria()? "Si":"No");
                }

        if(tipo=="Discoteca"){
                    const Discoteca* d= dynamic_cast<const Discoteca*>(toSave);
                     writer.writeAttribute("ingresso",d->getIngresso()? "Si": "No");
                     writer.writeAttribute("prezzo_ingresso", QString("%1").arg(d->getP_ing()));

                }
        if(tipo=="Discobar"){
                const Discobar* a= dynamic_cast<const Discobar*>(toSave);
                writer.writeAttribute("postiASedere",a->getPostiASedere()? "Si": "No");
                writer.writeAttribute("ingresso",a->getIngresso()? "Si": "No");
                writer.writeAttribute("prezzo_ingresso", QString("%1").arg(a->getP_ing()));
                writer.writeAttribute("costo_drink", QString::fromStdString(a->getCosto_drink()));
                }


        if(writer.hasError()){
            throw std::exception();
        }

        ++iter;
    }

    // chiude eventuali tag rimasti aperti.
    writer.writeEndElement();
    writer.writeEndDocument();

    file.commit();
    dataSaved=true;

}


void Model::load(){

    QFile file(QString::fromStdString(path));

    if(!file.open(QIODevice::ReadOnly)){
        throw FileException("Errorre in apertura del file.");
    }

    QXmlStreamReader reader(&file);
    if(reader.readNextStartElement()){
        if(reader.name()=="root"){
            while(reader.readNextStartElement()){
                const QXmlStreamAttributes att= reader.attributes();

                string rating= att.hasAttribute("rating")? att.value("rating").toString().toStdString(): "";
                string oraApertura= att.hasAttribute("oraApertura")? att.value("oraApertura").toString().toStdString(): "";
                string oraChiusura= att.hasAttribute("oraChiusura")? att.value("oraChiusura").toString().toStdString(): "";
                string nome= att.hasAttribute("nome")? att.value("nome").toString().toStdString(): "";
                string citta= att.hasAttribute("citta")? att.value("citta").toString().toStdString(): "";
                string descrizione= att.hasAttribute("descrizione")? att.value("descrizione").toString().toStdString(): "";
                string indirizzo= att.hasAttribute("indirizzo")? att.value("indirizzo").toString().toStdString(): "";


                bool postiFuori=false;
                bool siPaga=false;
                unsigned int ping=0;

                Locale* Push=nullptr;

                if(reader.name()=="Bar"){
                    postiFuori= att.hasAttribute("postiASedere")?att.value("postiASedere").toString()=="Si"? true: false : false;

                    Push= new Bar(rating, oraApertura, oraChiusura, nome, citta, descrizione, indirizzo, postiFuori);
                }
                if(reader.name()=="Ristorante"){
                    bool coperto= att.hasAttribute("coperto")?att.value("coperto").toString()=="Si"? true: false : false;

                    Push= new Ristorante(rating, oraApertura, oraChiusura, nome, citta, descrizione, indirizzo, coperto);
                }
                if(reader.name()=="Pasticceria"){
                    std::string spec=att.hasAttribute("specialita") ? att.value("specialita").toString().toStdString() : "";
                    bool caffe=att.hasAttribute("caffetteria")?att.value("caffetteria").toString()=="Si"? true: false : false;

                    Push= new Pasticceria(rating, oraApertura, oraChiusura, nome, citta, descrizione, indirizzo, spec, caffe);
                }
                if(reader.name()=="Discoteca"){
                    siPaga= att.hasAttribute("ingresso")?att.value("ingresso").toString()=="Si"? true: false : false;
                    ping=att.hasAttribute("prezzo_ingresso")?att.value("prezzo_ingresso").toUInt() : 0;

                    Push= new Discoteca(rating, oraApertura, oraChiusura, nome, citta, descrizione, indirizzo, siPaga, ping);
                }
                if(reader.name()=="Discobar"){
                    postiFuori= att.hasAttribute("postiASedere")?att.value("postiASedere").toString()=="Si"? true: false : false;
                    siPaga= att.hasAttribute("ingresso")?att.value("ingresso").toString()=="Si"? true: false : false;
                    ping=att.hasAttribute("prezzo_ingresso")?att.value("prezzo_ingresso").toUInt() : 0;
                    string costo_drink=att.hasAttribute("costo_drink")?att.value("costo_drink").toString().toStdString(): "";
                    Push= new Discobar(rating, oraApertura, oraChiusura, nome, citta, descrizione, indirizzo, postiFuori, siPaga, ping, costo_drink);
                }


                if(Push!= nullptr){
                    push_end(Push);
                }
                else throw
                    std::exception();

                if(!reader.isEndDocument())
                    reader.skipCurrentElement();
            }
        }
    }
    file.close();
    dataSaved=true;
}





