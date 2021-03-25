#include "localelistwidget.h"


LocaleListWidget::LocaleListWidget(QWidget *p):parent(p)
{
    addScrollBarWidget(new QScrollBar(Qt::Orientation::Vertical,parent), Qt::AlignRight);
    setAlternatingRowColors(true);
    setStyleSheet("QListWidget{ color:#111;font-weight:bold;}");
}

LocaleItems *LocaleListWidget::getItems(int i)
{
    LocaleItems* p=static_cast<LocaleItems*>(QListWidget::takeItem(i));
    return p;
}

LocaleItems *LocaleListWidget::currItems() const
{
    return static_cast<LocaleItems*>(QListWidget::currentItem());
}

LocaleItems *LocaleListWidget::getItems(Locale*removeFrom)
{
    bool found=false;
    LocaleItems* t=nullptr;
    for(int i=0; i<count()&& !found; i++){
        LocaleItems* tmp=static_cast<LocaleItems*>(item(i));
        if(tmp->getItemAddress()==removeFrom){
            t=static_cast<LocaleItems*>(getItems(i));
            found=true;
        }
    }
    return t;
}

void LocaleListWidget::aggiungiLocale(Locale *l)
{
    LocaleItems* item= new LocaleItems(l, parent);

    addItem(item);
}



