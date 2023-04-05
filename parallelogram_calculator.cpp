#include "parallelogram_calculator.h"
#include "ui_parallelogram_calculator.h"
#include <QGraphicsScene>

Parallelogram_calculator::Parallelogram_calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Parallelogram_calculator)
{
    ui->setupUi(this);

    // Connect the combo box to the stacked widget
      connect(ui->functionlist, SIGNAL(currentIndexChanged(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));

    // Set the initial page of the stacked widget
    ui->stackedWidget->setCurrentIndex(0);

    // Create a QGraphicsScene to hold the parallelogram diagram
       QGraphicsScene* scene = new QGraphicsScene();
        ui->Area_diagram->setScene(scene);
        ui->Perimeter_diagram->setScene(scene);
        ui->Height_diagram->setScene(scene);

       // Draw the parallelogram on the QGraphicsScene
       QPolygonF parallelogram;
       parallelogram << QPointF(0, 0) << QPointF(200, 0) << QPointF(150, 100) << QPointF(-50, 100);
       scene->addPolygon(parallelogram);

}

Parallelogram_calculator::~Parallelogram_calculator()
{
    delete ui;
}




