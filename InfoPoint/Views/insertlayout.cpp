#include "insertlayout.h"
#include "Controllers/controller.h"
#include <QSizePolicy>
#include <QMenuBar>


void insertLayout::slotResetCampi() const
{
      qlRating->setText("");
      qlNewNomeLocale->setText("");
      qlNewCittaLocale->setText("");
      qlNewIndirizzoLocale->setText("");
      insertApertura->setText("");
      insertChiusura->setText("");
      editDescrizione->setText("");
      comboTipoLocale->setCurrentIndex(0);
      siPagaCoperto->setChecked(false);
      SiPagaIngresso->setChecked(false);
      PostiaSedere->setChecked(false);
      coffee->setChecked(false);
      insertPrezzoDrink->setText("");
      Specialita->setText("");
      PIngresso->setText("");
}

insertLayout::insertLayout(QWidget* p):QWidget(p),
    qlRating(new QLineEdit(this)),
    insertApertura(new QLineEdit(this)),
    insertChiusura(new QLineEdit(this)),
    qlNewNomeLocale(new QLineEdit(this)),
    qlNewCittaLocale(new QLineEdit(this)),
    qlNewIndirizzoLocale(new QLineEdit(this)),
    insertPrezzoDrink(new QLineEdit(this)),
    Specialita(new QLineEdit(this)),
    editDescrizione(new QTextEdit(this)),
    PIngresso(new QLineEdit(this)),
    comboTipoLocale(new CombTipoLocale(this)),
    siPagaCoperto(new QCheckBox("Si paga il coperto",this)),
    SiPagaIngresso(new QCheckBox("Si paga l'ingresso",this)),
    PostiaSedere(new QCheckBox("Posti a sedere",this)),
    coffee(new QCheckBox("Caffetteria", this)),
    btNewLocaleConfirme(new QPushButton("Aggiungi",this)),
    btNewLocaleReset(new QPushButton("Resetta i campi",this)),
    dimBott(QSize(120 ,30))

{
    QVBoxLayout *insertMainLayout = new QVBoxLayout(this);
    QGridLayout* gridL=new QGridLayout();
    QGridLayout* grid= new QGridLayout();

    QLabel* label_titolo = new QLabel("Aggiungi nuovo Locale:");
    label_titolo->setStyleSheet("QLabel{font-size : 10pt; font-weight: bold; color:#007c86;}");
    label_titolo->setAlignment(Qt::AlignCenter);
    insertMainLayout->addWidget(label_titolo);
    insertMainLayout->addItem(gridL);
    gridL->setHorizontalSpacing(80);
    gridL->setVerticalSpacing(10);
    gridL->setMargin(10);

    QLabel *label_nome = new QLabel("Nome del Locale");
    label_nome->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#007c86; padding-top: 6px;}");
    qlNewNomeLocale->setPlaceholderText("Inserisci il nome del locale:");

    gridL->addWidget(label_nome, 0, 1);
    gridL->addWidget(qlNewNomeLocale, 2, 1);

    QLabel *label_rating = new QLabel("Valutazione:");
    label_rating->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#007c86;}");
    qlRating->setPlaceholderText("Voto[0/10] o Giudizio");
    //QRegExp QLR("[0-9]|10");
    //qlRating->setValidator(new QRegExpValidator(QLR));
    gridL->addWidget(label_rating, 3, 1);
    gridL->addWidget(qlRating, 4, 1);



    QLabel * label_tipo = new QLabel("Seleziona tipologia del Locale:");
    label_tipo->setAlignment(Qt::AlignLeft);
    label_tipo->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#007c86;}");
    comboTipoLocale->setStyleSheet("QComboBox{font-size : 10pt; font-weight: bold; color:#007c86;}");
    gridL->addWidget(label_tipo, 5, 1);
    gridL->addWidget(comboTipoLocale, 6, 1);

     insertMainLayout->addItem(grid);
     grid->setColumnStretch(4, 5);

     grid->setSpacing(5);
     grid->addWidget(PostiaSedere);
     grid->addWidget(siPagaCoperto);
     grid->addWidget(SiPagaIngresso);
     grid->addWidget(coffee);

    QLabel* label_prezzoDrink=new QLabel("Prezzi Drink:");
    label_prezzoDrink->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#007c86;}");
    insertPrezzoDrink->setPlaceholderText("Scrivere costo base dei drink");
    gridL->addWidget(label_prezzoDrink, 7, 1);
    gridL->addWidget(insertPrezzoDrink, 8, 1);

    QLabel* label_prezzoING=new QLabel("Prezzo Ingresso:");
    label_prezzoING->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#007c86;}");
    PIngresso->setPlaceholderText("Scrivere prezzo ingresso");
    QRegExp PI("^([1-9][0-9]{0,2}|1000)$");
    PIngresso->setValidator(new QRegExpValidator(PI));
    gridL->addWidget(label_prezzoING, 9, 1);
    gridL->addWidget(PIngresso, 10, 1);

    QLabel* label_spec=new QLabel("Specialità:");
    label_spec->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#007c86;}");
    Specialita->setPlaceholderText("Scrivere la specialità");
    gridL->addWidget(label_spec, 11, 1);
    gridL->addWidget(Specialita, 12, 1);


    QLabel *label_citta = new QLabel("Città:");
    label_citta->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#007c86;}");
    qlNewCittaLocale->setPlaceholderText("Città in cui si trova");
    gridL->addWidget(label_citta, 1, 2);
    gridL->addWidget(qlNewCittaLocale, 2, 2);


    QLabel *label_indirizzo = new QLabel("Indirizzo:");
    label_indirizzo->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#007c86;}");
    qlNewIndirizzoLocale->setPlaceholderText("Inserisci l'indirizzo");
    gridL->addWidget(label_indirizzo, 3, 2);
    gridL->addWidget(qlNewIndirizzoLocale, 4, 2);


    QLabel *label_apertura = new QLabel("Apre alle:");
    label_apertura->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#007c86;}");
    insertApertura->setPlaceholderText("Inserire l'orario di apertura");
    QRegExp IA("^([0-1]?[0-9]|2[0-4]):[0-5][0-9] [AaPp][Mm]$");
    insertApertura->setValidator(new QRegExpValidator(IA));
    gridL->addWidget(label_apertura, 5, 2);
    gridL->addWidget(insertApertura, 6, 2);


    QLabel *label_chiusura = new QLabel("Chiude alle:");
    label_chiusura->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#007c86;}");
    insertChiusura->setPlaceholderText("Inserire l'orario di chiusura");
    QRegExp IC("^([0-1]?[0-9]|2[0-4]):[0-5][0-9] [AaPp][Mm]$");
    insertChiusura->setValidator(new QRegExpValidator(IC));
    gridL->addWidget(label_chiusura, 7, 2);
    gridL->addWidget(insertChiusura, 8, 2);


    QLabel *label_desc = new QLabel("Descrizione:");
    label_desc->setStyleSheet("QLabel{font-size : 9pt; font-weight: bold; color:#007c86;}");
    editDescrizione->setPlaceholderText("Descrivi il locale");
    insertMainLayout->addWidget(label_desc);
    insertMainLayout->addWidget(editDescrizione);


    QHBoxLayout*HBlayout=new QHBoxLayout();
    HBlayout->addWidget(btNewLocaleConfirme);
    btNewLocaleConfirme->setFixedSize(dimBott);
    HBlayout->addWidget(btNewLocaleReset);
    btNewLocaleReset->setFixedSize(dimBott);



        slotDisableElements(0);

        insertMainLayout->addLayout(HBlayout);
        connect(comboTipoLocale,SIGNAL(activated(int)),this,SLOT(slotDisableElements(int)));
        connect(btNewLocaleReset,SIGNAL(clicked()),this,SLOT(slotResetCampi()));




}



CombTipoLocale *insertLayout::getTipoLocale()const
{
    return comboTipoLocale;
}

QCheckBox *insertLayout::getPagaCoperto() const
{
    return siPagaCoperto;
}

QCheckBox *insertLayout::getPagaIngresso() const
{
    return SiPagaIngresso;
}

QCheckBox *insertLayout::getPostiaSedere() const
{
    return PostiaSedere;
}

QCheckBox* insertLayout::getcoffe()const{
    return coffee;
}

QLineEdit* insertLayout::getPIngresso() const{
    return PIngresso;
}

QLineEdit* insertLayout::getSpecial() const{
    return Specialita;
}

QLineEdit* insertLayout::getInsertPrezzoDrink() const{
    return insertPrezzoDrink;
}

QLineEdit *insertLayout::getqlRating() const
{
    return qlRating;
}

QLineEdit *insertLayout::getNome() const
{
    return qlNewNomeLocale;
}

QLineEdit *insertLayout::getCitta() const
{
    return qlNewCittaLocale;
}

QLineEdit *insertLayout::getIndirizzo() const
{
    return qlNewIndirizzoLocale;
}

QLineEdit *insertLayout::getApertura() const
{
    return insertApertura;
}

QLineEdit *insertLayout::getChiusura() const
{
    return insertChiusura;
}


QTextEdit *insertLayout::getDescrizione() const
{
    return editDescrizione;
}
QPushButton *insertLayout::getBtConfirme() const
{
    return  btNewLocaleConfirme;
}

QPushButton *insertLayout::getBtCancel() const
{
    return btNewLocaleCancel;
}

void insertLayout::slotDisableElements(int i) const
{
    switch (i) {

    case 0: //Nulla
        siPagaCoperto->setEnabled(false);
        SiPagaIngresso->setEnabled(false);
        PostiaSedere->setEnabled(false);
        insertPrezzoDrink->setEnabled(false);
        Specialita->setEnabled(false);
        coffee->setEnabled(false);
        PIngresso->setEnabled(false);

        break;

    case 1: //Bar
        siPagaCoperto->setEnabled(false);
        SiPagaIngresso->setEnabled(false);
        PostiaSedere->setEnabled(true);
        insertPrezzoDrink->setEnabled(false);
        PIngresso->setEnabled(false);
        Specialita->setEnabled(false);
        coffee->setEnabled(false);


        break;

    case 2: //Ristorante
        siPagaCoperto->setEnabled(true);
        SiPagaIngresso->setEnabled(false);
        PostiaSedere->setEnabled(false);
        insertPrezzoDrink->setEnabled(false);
        PIngresso->setEnabled(false);
        Specialita->setEnabled(false);
        coffee->setEnabled(false);

        break;

    case 3: //Pasticceria
        siPagaCoperto->setEnabled(false);
        SiPagaIngresso->setEnabled(false);
        PostiaSedere->setEnabled(false);
        insertPrezzoDrink->setEnabled(false);
        PIngresso->setEnabled(false);
        Specialita->setEnabled(true);
        coffee->setEnabled(true);

        break;

    case 4: //Discoteca
        siPagaCoperto->setEnabled(false);
        SiPagaIngresso->setEnabled(true);
        PostiaSedere->setEnabled(false);
        insertPrezzoDrink->setEnabled(false);
        PIngresso->setEnabled(true);
        Specialita->setEnabled(false);
        coffee->setEnabled(false);

        break;

    case 5: //Discobar
        siPagaCoperto->setEnabled(false);
        SiPagaIngresso->setEnabled(true);
        PostiaSedere->setEnabled(true);
        insertPrezzoDrink->setEnabled(true);
        PIngresso->setEnabled(true);
        Specialita->setEnabled(false);
        coffee->setEnabled(false);

        break;

    }
}


