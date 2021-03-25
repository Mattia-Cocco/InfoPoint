#ifndef LAYOUTVIEW_H
#define LAYOUTVIEW_H



#include "localelistwidget.h"
#include "layoutviewitem.h"
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QFile>



class LayoutView: public QWidget
{
    Q_OBJECT
private:
    QPushButton* buttonElimina;
    QPushButton*btModifica;
    LocaleListWidget* listwidget;
    LayoutViewItem* dialog;
    QWidget *parent;
    const QSize DimBott;
public:
    explicit LayoutView(QWidget* parent=nullptr);
    ~LayoutView();
    LocaleListWidget *getListWidget() const;

    QPushButton *getBtnElimina()const;
    QPushButton *getBtnModifica()const;


public slots:
    void slotRChanged()const;

    void slotElementSelected(bool=true)const;

signals:
    void signalElementSelected(bool=true)const;



};

#endif // LAYOUTVIEW_H
