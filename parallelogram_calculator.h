#ifndef PARALLELOGRAM_CALCULATOR_H
#define PARALLELOGRAM_CALCULATOR_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QMessageBox>
#include <QDebug>
#include <QMouseEvent>
#include <QPointF>
#include <QPen>
#include <QPolygonF>
#include <QFocusEvent>
#include <QGuiApplication>

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

    void highlightBaseLine(QGraphicsView *view);
    void highlightHeightLine(QGraphicsView *view);
    void highlightSideLine(QGraphicsView *view);
    void highlightArea(QGraphicsView *view);


private:
    Ui::Parallelogram_calculator *ui;

    QGraphicsLineItem* baseLineItem;
    QGraphicsLineItem* heightLineItem;
    QGraphicsLineItem* sideLineItem;



protected:
    void paintEvent(QPaintEvent *e);

};
#endif // PARALLELOGRAM_CALCULATOR_H
