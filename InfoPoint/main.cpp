#include "Controllers/controller.h"
#include "Models/model.h"
#include <QApplication>
#include <QPalette>
#include <QWidget>



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);


    QPalette pal= QApplication::palette();
    pal.setColor(QPalette::Window, QColor("#fff")); //backgroundColor
    QApplication::setPalette(pal);

    Controller w(new Model());
    w.show();

    return a.exec();
}
