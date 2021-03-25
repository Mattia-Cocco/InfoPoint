#ifndef SEARCHLAYOUT_H
#define SEARCHLAYOUT_H

#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QPushButton>
#include <QFormLayout>
#include <QMessageBox>
#include <qlabel.h>

#include "Models/model.h"
#include "Views/localelistwidget.h"
#include "Views/combtipolocale.h"

class SearchLayout: public QWidget
{
    Q_OBJECT
private:
    QLineEdit *searchByNome;
    QLineEdit *searchByCitta;

    QCheckBox *boxNome;
    QCheckBox *boxCitta;
    QCheckBox *boxTipo;


    CombTipoLocale *searchByTipo;
    Model * model;
    LocaleListWidget *listaLocali;

    QPushButton *cerca;
    QPushButton *resetta;
    QPushButton *btnEliminaTrovato;

    const QSize dimBott;
public:
    SearchLayout(QWidget* =nullptr);


    QLineEdit *getSearchByNome() const;
    QLineEdit *getSearchByCitta() const;


    CombTipoLocale *getSearchByTipo() const;
    QPushButton *getCerca() const;
    QPushButton *getResetta() const;

    LocaleListWidget *getListaLocali() const;

    QPushButton *getBtnEliminaTrovato() const;
    QCheckBox *getBoxNome() const;
    QCheckBox *getBoxCitta() const;

    QCheckBox *getBoxTipo() const;


private slots:

    void slotDisableElements()const;

public slots:
    void slotResetRicerca()const;
signals:
    void signalEliminaTuttiElementi(Model*);
};

#endif // SEARCHLAYOUT_H
