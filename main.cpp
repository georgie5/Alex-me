#include "parallelogram_calculator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Parallelogram_calculator w;
    w.show();
    return a.exec();
}
