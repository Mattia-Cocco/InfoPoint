#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <qmenubar.h>
#include <qwidget.h>

class mainMenu : public QMenuBar
{
    Q_OBJECT
    QWidget*parent;
    QMenu* menu;

    QAction*save;
    QAction*load;
    QAction*exit;

    QAction* ricerca;
    QAction* inserisci;
    QAction* views;
    QMenu * help;
    QAction* segnalaBug;



public:
    mainMenu(QWidget* =nullptr);
    QAction*getExit()const;
    QMenu*getMenu()const;
    QAction* getSave()const;

    mainMenu*getAbout()const;
    QMenu*getTool()const;
    QAction *getLoad()const;

    QMenu*getHelp()const;
    QAction  *getViewBug()const;
    QAction *getRicerca()const;

};

#endif // MAINVIEW_H
