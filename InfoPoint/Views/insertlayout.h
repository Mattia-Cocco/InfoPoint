#ifndef INSERTLAYOUT_H
#define INSERTLAYOUT_H

#include <QDialog>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QFormLayout>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QTextEdit>
#include <QRegExp>
#include <QRegExpValidator>
#include <QAbstractScrollArea>

#include "combtipolocale.h"





class insertLayout: public QWidget
{
    Q_OBJECT
private:
    QLineEdit* qlRating;
    QLineEdit* insertApertura;
    QLineEdit* insertChiusura;
    QLineEdit* qlNewNomeLocale;
    QLineEdit* qlNewCittaLocale;
    QLineEdit* qlNewIndirizzoLocale;
    QLineEdit* insertPrezzoDrink;
    QLineEdit* Specialita;
    QTextEdit* editDescrizione;
    QLineEdit* PIngresso;


    CombTipoLocale* comboTipoLocale;

    QCheckBox* siPagaCoperto;
    QCheckBox* SiPagaIngresso;
    QCheckBox* PostiaSedere;
    QCheckBox* coffee;


    QPushButton * btNewLocaleConfirme;
    QPushButton * btNewLocaleReset;
    QPushButton * btNewLocaleCancel;

    const QSize dimBott;


private slots:
    void slotResetCampi()const;
public:
    insertLayout(QWidget* =nullptr);
    QGroupBox* groubBoxItem();

    CombTipoLocale* getTipoLocale()const;

    QCheckBox* getPagaCoperto()const;
    QCheckBox* getPagaIngresso()const;
    QCheckBox* getPostiaSedere() const;
    QCheckBox* getSiMangia()const;
    QCheckBox* getcoffe()const;

    QLineEdit* getqlRating()const;
    QLineEdit* getNome()const;
    QLineEdit* getCitta()const;
    QLineEdit* getIndirizzo()const;
    QLineEdit* getinsertPrezzoPersona()const;
    QLineEdit* getApertura()const;
    QLineEdit* getChiusura()const;
    QLineEdit* getInsertPrezzoDrink()const;
    QLineEdit* getSpecial()const;
    QLineEdit* getPIngresso()const;

    QTextEdit* getDescrizione()const;

    QPushButton* getBtConfirme()const;
    QPushButton* getBtCancel()const;

public slots:
    void slotDisableElements(int)const;

signals:
    void signalDisableElements(int);
};

#endif // INSERTLAYOUT_H
