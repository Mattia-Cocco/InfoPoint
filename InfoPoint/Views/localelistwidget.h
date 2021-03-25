#ifndef LOCALELISTWIDGET_H
#define LOCALELISTWIDGET_H
#include <QListWidget>
#include <QPushButton>
#include <QScrollBar>
#include"Views/localeitems.h"



class LocaleListWidget: public QListWidget
{

    Q_OBJECT
private:
    QWidget* parent;
public:
    LocaleListWidget(QWidget* =nullptr);
    LocaleItems* getItems(int);
    LocaleItems* currItems()const;
    LocaleItems* getItems(Locale*);
    void aggiungiLocale(Locale*);


signals:
    void signalDeleteFromList(Locale*);
};

#endif // LOCALELISTWIDGET_H
