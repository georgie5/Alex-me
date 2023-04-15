#include "parallelogram_calculator.h"
#include "qgraphicsitem.h"
#include "ui_parallelogram_calculator.h"
#include <QGraphicsScene>
#include <QPainter>
<<<<<<< HEAD
#include "qgraphicsitem.h"
=======
>>>>>>> ba1d64e0738da742e4a95386a36ea2d2a6fd9065

Parallelogram_calculator::Parallelogram_calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Parallelogram_calculator)


{
    ui->setupUi(this);

<<<<<<< HEAD
       // Connect the combo box to the stacked widget
         connect(ui->functionlist, SIGNAL(currentIndexChanged(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));

       // Set the initial page of the stacked widget
         ui->stackedWidget->setCurrentIndex(0);
//-----------------------------------------------------------------------------

=======
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



>>>>>>> ba1d64e0738da742e4a95386a36ea2d2a6fd9065

}
Parallelogram_calculator::~Parallelogram_calculator()
{
    delete ui;
}

<<<<<<< HEAD
void Parallelogram_calculator::paintEvent(QPaintEvent *e)
{
    // Draw the Diagram into the graphic view
    //---------------------------------------------------------------
    e->accept();//to avoid warning

    // Create a QGraphicsScene to hold the parallelogram diagram
    QGraphicsScene *scene = new QGraphicsScene();
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

    //HIGHLIGHT THE DIFFERENT LINES OF THE DIAGRAM
//----------------------------------------------------------------------------------------
    if(ui->stackedWidget->currentIndex() == 0)
    {
          if (ui->Area_base_input->hasFocus() == true ) {

              ui->Area_diagram->scene()->clear();
              highlightBaseLine(ui->Area_diagram);
          }
          else if (ui->Area_height_input->hasFocus() == true){
               ui->Area_diagram->scene()->clear();
               highlightHeightLine(ui->Area_diagram);
          }


    }
    else if(ui->stackedWidget->currentIndex() ==1)
    {
        if(ui->P_base_input->hasFocus()== true){

            ui->Perimeter_diagram->scene()->clear();
            highlightBaseLine(ui->Perimeter_diagram);
        }
        else if(ui->P_side_input->hasFocus() == true)
        {
             ui->Perimeter_diagram->scene()->clear();
            highlightSideLine(ui->Perimeter_diagram);
        }

    }
    else if(ui->stackedWidget->currentIndex() == 2)
    {
        if(ui->H_base_input->hasFocus()==true)
        {
            ui->Height_diagram->scene()->clear();
            highlightBaseLine( ui->Height_diagram);
        }
        else if(ui->H_area_input->hasFocus()==true)
        {
            ui->Height_diagram->scene()->clear();
            highlightArea( ui->Height_diagram);
        }
    }
}


void Parallelogram_calculator::highlightBaseLine(QGraphicsView *view) //highlight the baseline function
{
    QGraphicsScene *base = new QGraphicsScene(this);

    //ui->Area_diagram->setScene(base);
    view->setScene(base);
    // Draw the parallelogram on the QGraphicsScene
    QPolygonF parallelogram;
    parallelogram << QPointF(0, 0) << QPointF(200, 0) << QPointF(150, 100) << QPointF(-50, 100);

    QGraphicsTextItem *textItem1 = new QGraphicsTextItem("b");
    textItem1->setPos(80, -23);
    textItem1->setDefaultTextColor(Qt::red);

    QGraphicsTextItem *textItem2 = new QGraphicsTextItem("a");
    textItem2->setPos(-40, 30);

    base->addPolygon(parallelogram);
    base->addItem(textItem1);
    base->addItem(textItem2);

    // Add a vertical line labeled H to the QGraphicsScene
    QLineF line(QPointF(0, 0), QPointF(0, 100));
    QGraphicsLineItem* itemH = new QGraphicsLineItem(line);
    QGraphicsSimpleTextItem* textH = new QGraphicsSimpleTextItem("h");
    textH->setPos(5, 50);
    base->addItem(itemH);
    base->addItem(textH);

    // Initialize the member variables for the lines
   QGraphicsLineItem* m_baseLineItem = new QGraphicsLineItem(QLineF(QPointF(0, 0), QPointF(200, 0)));

    // Set the pen for the lines
    QPen pen(Qt::red);
    pen.setWidth(2);
    m_baseLineItem->setPen(pen);
    // Add the lines to the QGraphicsScene
    base->addItem(m_baseLineItem);


}

void Parallelogram_calculator::highlightHeightLine(QGraphicsView *view) //highlight the heightline function
{
    QGraphicsScene *height = new QGraphicsScene(this);

  //  ui->Area_diagram->setScene(height);
    view->setScene(height);
    // Draw the parallelogram on the QGraphicsScene
    QPolygonF parallelogram;
    parallelogram << QPointF(0, 0) << QPointF(200, 0) << QPointF(150, 100) << QPointF(-50, 100);

    QGraphicsTextItem *textItem1 = new QGraphicsTextItem("b");
    textItem1->setPos(80, -23);

    QGraphicsTextItem *textItem2 = new QGraphicsTextItem("a");
    textItem2->setPos(-40, 30);

    height->addPolygon(parallelogram);
    height->addItem(textItem1);
    height->addItem(textItem2);

    // Add a vertical line labeled H to the QGraphicsScene
    QLineF line(QPointF(0, 0), QPointF(0, 100));
    QGraphicsLineItem* itemH = new QGraphicsLineItem(line);

    QGraphicsSimpleTextItem* textH = new QGraphicsSimpleTextItem("h");
    textH->setPos(5, 50);
    textH->setBrush(Qt::red);

    height->addItem(itemH);
    height->addItem(textH);


    QGraphicsLineItem* m_heightLineItem = new QGraphicsLineItem(QLineF(QPointF(0, 0), QPointF(0, 100)));
   // m_areaLineItem = new QGraphicsLineItem(QLineF(QPointF(200, 0), QPointF(150, 100)));

    // Set the pen for the lines
    QPen pen(Qt::red);
    pen.setWidth(2);

    m_heightLineItem->setPen(pen);
   // m_areaLineItem->setPen(pen);
    height->addItem(m_heightLineItem);
}

void Parallelogram_calculator::highlightSideLine(QGraphicsView *view) //highlight the sideline function
{
    QGraphicsScene *side = new QGraphicsScene(this);

  //  ui->Area_diagram->setScene(side);
    view->setScene(side);
    // Draw the parallelogram on the QGraphicsScene
    QPolygonF parallelogram;
    parallelogram << QPointF(0, 0) << QPointF(200, 0) << QPointF(150, 100) << QPointF(-50, 100);

    QGraphicsTextItem *textItem1 = new QGraphicsTextItem("b");
    textItem1->setPos(80, -23);

    QGraphicsTextItem *textItem2 = new QGraphicsTextItem("a");
    textItem2->setPos(-40, 30);
    textItem2->setDefaultTextColor(Qt::red);

    side->addPolygon(parallelogram);
    side->addItem(textItem1);
    side->addItem(textItem2);

    // Add a vertical line labeled H to the QGraphicsScene
    QLineF line(QPointF(0, 0), QPointF(0, 100));
    QGraphicsLineItem* itemH = new QGraphicsLineItem(line);
    QGraphicsSimpleTextItem* textH = new QGraphicsSimpleTextItem("h");
    textH->setPos(5, 50);
    side->addItem(itemH);
    side->addItem(textH);

    QGraphicsLineItem *sideLineItem = new QGraphicsLineItem(QLineF(QPointF(0, 0), QPointF(-50, 100)));
    // Set the pen for the lines
    QPen pen(Qt::red);
    pen.setWidth(2);

    sideLineItem->setPen(pen);
   // m_areaLineItem->setPen(pen);
    side->addItem(sideLineItem);
}

void Parallelogram_calculator::highlightArea(QGraphicsView *view) //highlight the area function
{
    QGraphicsScene *area = new QGraphicsScene(this);

    view->setScene(area);
    // Draw the parallelogram on the QGraphicsScene

    QPolygonF parallelogram;
    parallelogram << QPointF(0, 0) << QPointF(200, 0) << QPointF(150, 100) << QPointF(-50, 100);

    QGraphicsTextItem *textItem1 = new QGraphicsTextItem("b");
    textItem1->setPos(80, -23);

    QGraphicsTextItem *textItem2 = new QGraphicsTextItem("a");
    textItem2->setPos(-40, 30);

    QGraphicsTextItem *textItem3 = new QGraphicsTextItem("A");
    textItem3->setPos(60, 30);
    textItem3->setDefaultTextColor(Qt::red);
    QFont font;
    font.setPointSize(20);
    textItem3->setFont(font);

    area->addPolygon(parallelogram);
    area->addItem(textItem1);
    area->addItem(textItem2);
    area->addItem(textItem3);

    // Add a vertical line labeled H to the QGraphicsScene
    QLineF line(QPointF(0, 0), QPointF(0, 100));
    QGraphicsLineItem* itemH = new QGraphicsLineItem(line);
    QGraphicsSimpleTextItem* textH = new QGraphicsSimpleTextItem("h");
    textH->setPos(5, 50);
    area->addItem(itemH);
    area->addItem(textH);

    QGraphicsPolygonItem* parallelogramItem = new QGraphicsPolygonItem(parallelogram);
    QBrush brush(QColor(255, 0, 0, 50)); // Set the brush color and opacity
    parallelogramItem->setBrush(brush);
    area->addItem(parallelogramItem);



}



=======
>>>>>>> ba1d64e0738da742e4a95386a36ea2d2a6fd9065
