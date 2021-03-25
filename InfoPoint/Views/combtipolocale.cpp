#include "combtipolocale.h"



CombTipoLocale::CombTipoLocale(QWidget *p):QComboBox(p)
{
    addItem("Seleziona locale");
    addItem("Bar");
    addItem("Ristorante");
    addItem("Pasticceria");
    addItem("Discoteca");
    addItem("Discobar");
}
