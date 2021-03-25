#ifndef LAYOUTVIEWITEM_H
#define LAYOUTVIEWITEM_H

#include "Models/model.h"
#include "localeitems.h"
#include "insertlayout.h"

#include <QDialog>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>
#include <QString>
#include <QFileInfo>
#include <QFileDialog>
#include <QBuffer>

class LayoutViewItem: public QDialog
{
    Q_OBJECT
private:

    LocaleItems *listItem;
    QTextEdit* descrizione;
    QTextEdit* indirizzo;
    QTextEdit* citta;
    QTextEdit* nome;
    Locale* loc;
    QPushButton *closeButton;
    QPushButton *saveModifica;

    QTextEdit* Lcitta;

public:
    LayoutViewItem(LocaleItems*,QWidget* =nullptr);

public slots:
    void slotSaveModifica()const;

};

#endif // LAYOUTVIEWITEM_H
