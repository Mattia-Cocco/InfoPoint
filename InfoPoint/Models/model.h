#ifndef MODEL_H
#define MODEL_H

#include "container.h"
#include "locale.h"
#include "ristoranti.h"
#include "bar.h"
#include "discoteca.h"
#include "pasticceria.h"
#include "discobar.h"
#include "fileexception.h"

#include <QSaveFile>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <QtXml>


class Model   // model
{
private:
    bool dataSaved;
    Container<Locale*>*lista_locali;
    Container<Locale*>*search;
    string path;
public:
    Model(string ="../InfoPoint/dati.xml");

    ~Model();

    void saveInFile();
    void push_end(Locale*);
    bool getDataSaved()const;
    void setDataSaved(bool);
    bool saveMod;
    void printAll()const;
    void erase(unsigned int);
    void erase(unsigned int, unsigned int);
    void erase(Locale*);
    void save();
    void load();
    void setNewPath(string);
    bool isEmpty()const;
    void clear();
    void deleteElemetiTrovati()const;
    void resetSearch()const;


    Locale *itemAtpos(unsigned int);
    Container<Locale *>::iterator begin();
    Container <Locale*>::iterator end();
    Container <Locale*>::const_iterator cbegin()const;
    Container <Locale*>::const_iterator cend()const;


    string getPath()const;
    unsigned int getDataSize()const;
    unsigned int getDataCapacity()const;
    unsigned int getResSize()const;
    Locale* resItemAtpos(unsigned int);
    Container<Locale*>:: const_iterator res_cbegin() const;
    Container<Locale*>:: const_iterator res_cend() const;

    void searchName(string nome)const;
    void searchType(string tipo)const;
    void searchCitta(string citta)const;




};

#endif // MODEL_H
