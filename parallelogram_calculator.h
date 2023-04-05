#ifndef PARALLELOGRAM_CALCULATOR_H
#define PARALLELOGRAM_CALCULATOR_H

#include <QMainWindow>
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
namespace Ui { class Parallelogram_calculator; }
QT_END_NAMESPACE

class Parallelogram_calculator : public QMainWindow
{
    Q_OBJECT

public:
    Parallelogram_calculator(QWidget *parent = nullptr);
    ~Parallelogram_calculator();

private slots:


private:
    Ui::Parallelogram_calculator *ui;
};
#endif // PARALLELOGRAM_CALCULATOR_H
