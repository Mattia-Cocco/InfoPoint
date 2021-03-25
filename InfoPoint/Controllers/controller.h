#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <QObject>
#include <QVBoxLayout>
#include <QDebug>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QLabel>
#include <iostream>
#include <QFileDialog>
#include <QBuffer>
#include <QRegExpValidator>
#include <QPalette>

#include "Views/insertlayout.h"
#include "Models/model.h"
#include "Views/mainMenu.h"
#include "Views/layoutview.h"
#include "Views/searchlayout.h"
#include "Views/layoutviewitem.h"

class Controller : public QWidget{
    Q_OBJECT
private:
    mainMenu* menuBar;
    Model* model;
    QHBoxLayout*mainLayout;
    LayoutView* viewLayout;
    SearchLayout*ricercaLayout;


    insertLayout* addLayoutView;
    LayoutViewItem*dialog;

public:

    Controller(Model*,QWidget* =nullptr);

     Model *getModel();
     ~Controller();



public slots:
     void slotViewRicerca()const;
     void slotViewInserisci()const;
     void slotViewVisualizza()const;
     void slotResetRicerca() const;
     void slotSaveData()const;
     void slotDataChanged(bool)const;



     void slotLoad() ;
     void slotRicerca();
     void slotViewSegnalaBug();
     void slotDeleteElement()const;
     void slotAddElement();

     void slotViewModifica();




    void slotDeleteFromModel(Locale*)const;
    void slotDeleteFromModel()const;


};
#endif // CONTROLLER_H
