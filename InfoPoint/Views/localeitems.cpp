#include "localeitems.h"



LocaleItems::LocaleItems(Locale *item, QWidget *p):
    item(item),
    parent(p)
{
    update();
}

Locale *LocaleItems::getItemAddress() const
{
    return item;
}

void LocaleItems::update()
{
     setText(QString::fromStdString(item->getInfo()));
}

bool LocaleItems::isEmpty()const
{
    if(item==nullptr)
        return true;
    else
        return false;
}
