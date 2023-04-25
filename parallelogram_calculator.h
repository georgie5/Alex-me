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
#include <QFile>
#include <QFileDialog>

#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QInputDialog>
#include <QClipboard>

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


    void on_actionOpen_triggered();

    void saveFile();

    void on_Area_Solve_Button_clicked();

    void on_H_Solve_Button_clicked();

    void on_P_Solve_Button_clicked();

    void on_actionNew_triggered();

    void hideToolbar();

    void ViewToolbar();

    void on_actionAbout_triggered();



    void on_actionPrint_triggered();

    void on_H_Clear_Button_clicked();

    void on_Area_Clear_Button_clicked();

    void on_P_Clear_Button_clicked();

    void updateConnections(int index);


private:
    Ui::Parallelogram_calculator *ui;

    QGraphicsLineItem* baseLineItem;
    QGraphicsLineItem* heightLineItem;
    QGraphicsLineItem* sideLineItem;



protected:
    void paintEvent(QPaintEvent *e);

};
#endif // PARALLELOGRAM_CALCULATOR_H
