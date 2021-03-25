#ifndef LOCALEITEMS_H
#define LOCALEITEMS_H
#include <QListWidgetItem>
#include <QByteArray>
#include "Models/locale.h"

class LocaleItems:public QListWidgetItem
{
private:
    Locale* item;
    QWidget * parent;
public:
    LocaleItems(Locale* , QWidget* =nullptr);
    Locale *getItemAddress()const;
    void update();
    bool isEmpty()const;
};

#endif // LOCALEITEMS_H


