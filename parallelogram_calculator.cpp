#include "parallelogram_calculator.h"
#include "qgraphicsitem.h"
#include "ui_parallelogram_calculator.h"
#include <QGraphicsScene>
#include <QPainter>

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

      QGraphicsTextItem *textItem1 = new QGraphicsTextItem("b");
      textItem1->setPos(80, -23);

      QGraphicsTextItem *textItem2 = new QGraphicsTextItem("a");
      textItem2->setPos(-40, 30);

      scene->addPolygon(parallelogram);
      scene->addItem(textItem1);
      scene->addItem(textItem2);


      // Add a vertical line labeled H to the QGraphicsScene
      QLineF line(QPointF(0, 0), QPointF(0, 100));
      QGraphicsLineItem* itemH = new QGraphicsLineItem(line);
      QGraphicsSimpleTextItem* textH = new QGraphicsSimpleTextItem("h");
      textH->setPos(5, 50);
      scene->addItem(itemH);
      scene->addItem(textH);




}
Parallelogram_calculator::~Parallelogram_calculator()
{
    delete ui;
}

