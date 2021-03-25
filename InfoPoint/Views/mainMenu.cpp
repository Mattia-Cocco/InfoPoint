#include "mainMenu.h"

mainMenu::mainMenu(QWidget *P):
    parent(P),
    menu(new QMenu("File", this)),
    save(new QAction("Salva", this)),
    load(new QAction("Carica nuovi dati", this)),
    exit(new QAction("Exit",menu)),
    ricerca(new QAction("Ricerca", this)),
    inserisci(new QAction("Inserisci",this)),
    views(new QAction("Visualizza",this)),
    help(new QMenu("Help", this)),
    segnalaBug(new QAction("Segnala errori",this))

{
    QList<QAction*>ActionItem;

    ActionItem.push_back(views);
    ActionItem.push_back(inserisci);
    ActionItem.push_back(ricerca);
    ActionItem.push_back(save);
    ActionItem.push_back(load);
    ActionItem.push_back(exit);
    menu->addActions(ActionItem);
    ActionItem.clear();


    addMenu(menu);
    addAction(views);
    addAction(inserisci);
    addAction(ricerca);
    ActionItem.push_back(segnalaBug);
    help->addActions(ActionItem);

    ActionItem.clear();
    addMenu(help);
    connect(exit,SIGNAL(triggered()),parent,SLOT(close()));
    connect(ricerca, SIGNAL(triggered()), parent,SLOT(slotViewRicerca()));
    connect(inserisci, SIGNAL(triggered()), parent,SLOT(slotViewInserisci()));
    connect(views, SIGNAL(triggered()), parent,SLOT(slotViewVisualizza()));
    connect(save,SIGNAL(triggered()),parent,SLOT(slotSaveData()));

    connect(segnalaBug,SIGNAL(triggered()),parent,SLOT(slotViewSegnalaBug()));
    connect(load,SIGNAL(triggered()),parent, SLOT(slotLoad()));



}

QAction *mainMenu::getExit() const
{
    return exit;
}

QMenu *mainMenu::getMenu() const
{
    return menu;
}

QAction *mainMenu::getSave() const
{
    return save;
}


QMenu*mainMenu::getHelp() const
{
    return help;
}



QAction*mainMenu::getLoad() const
{
    return load;
}

QAction*mainMenu::getViewBug() const
{
    return segnalaBug;
}

QAction *mainMenu::getRicerca() const
{
    return ricerca;
}


