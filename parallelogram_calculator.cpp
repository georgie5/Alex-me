#include "parallelogram_calculator.h"
#include "qgraphicsitem.h"
#include "ui_parallelogram_calculator.h"
#include <QGraphicsScene>
#include <QPainter>


#include "qgraphicsitem.h"



Parallelogram_calculator::Parallelogram_calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Parallelogram_calculator)


{
    ui->setupUi(this);


       // Connect the combo box to the stacked widget
         connect(ui->functionlist, SIGNAL(currentIndexChanged(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));

       // Set the initial page of the stacked widget
         ui->stackedWidget->setCurrentIndex(0);
//-----------------------------------------------------------------------------
         connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(actionNew()));
            connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(actionOpen()));
        connect(ui->actionSave, SIGNAL(triggered()),this,SLOT(saveFile()));
        connect(ui->actionClose,SIGNAL(triggered()),this,SLOT(close()));
        connect(ui->actionExit,SIGNAL(triggered()),qApp,SLOT(closeAllWindows()));

        connect(ui->actionHide_Toolbar,SIGNAL(triggered()),this,SLOT(hideToolbar()));
        connect(ui->actionShow_Toolbar,SIGNAL(triggered()),this,SLOT(ViewToolbar()));
        connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

        if(ui->stackedWidget->currentIndex() == 0)
        {

        }

        else if(ui->stackedWidget->currentIndex() == 1)
        {
            connect(ui->actionCut, &QAction::triggered, ui->P_base_input, &QLineEdit::cut);
            connect(ui->actionCut, &QAction::triggered, ui->P_side_input, &QLineEdit::cut);

            connect(ui->actionCopy, &QAction::triggered, ui->P_base_input, &QLineEdit::copy);
            connect(ui->actionCopy, &QAction::triggered, ui->P_side_input, &QLineEdit::copy);

            connect(ui->actionPaste, &QAction::triggered, ui->Area_base_input, [=]() { ui->P_base_input->paste(); });
            connect(ui->actionPaste, &QAction::triggered, ui->P_side_input, &QLineEdit::paste);

            connect(ui->actionUndo, &QAction::triggered, ui->P_base_input, &QLineEdit::undo);
            connect(ui->actionUndo, &QAction::triggered, ui->P_side_input, &QLineEdit::undo);

            connect(ui->actionRedo, &QAction::triggered, ui->P_base_input, &QLineEdit::redo);
            connect(ui->actionRedo, &QAction::triggered, ui->P_side_input, &QLineEdit::redo);


        }
        else if (ui->stackedWidget->currentIndex() == 2)
        {
            connect(ui->actionCut, &QAction::triggered, ui->H_base_input, &QLineEdit::cut);
            connect(ui->actionCut, &QAction::triggered, ui->H_area_input, &QLineEdit::cut);

            connect(ui->actionCopy, &QAction::triggered, ui->H_base_input, &QLineEdit::copy);
            connect(ui->actionCopy, &QAction::triggered, ui->H_area_input, &QLineEdit::copy);

            connect(ui->actionPaste, &QAction::triggered, ui->Area_base_input, [=]() { ui->H_base_input->paste(); });
            connect(ui->actionPaste, &QAction::triggered, ui->H_area_input, &QLineEdit::paste);

            connect(ui->actionUndo, &QAction::triggered, ui->H_base_input, &QLineEdit::undo);
            connect(ui->actionUndo, &QAction::triggered, ui->H_area_input, &QLineEdit::undo);

            connect(ui->actionRedo, &QAction::triggered, ui->H_base_input, &QLineEdit::redo);
            connect(ui->actionRedo, &QAction::triggered, ui->H_area_input, &QLineEdit::redo);


        }
}
Parallelogram_calculator::~Parallelogram_calculator()
{
    delete ui;
}


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


void Parallelogram_calculator::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt)"));
    if (filename.isEmpty()) return;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    // Display the file content in a new window
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle(filename);
    dialog->setModal(false); // set modal property to false
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QLabel* label = new QLabel(content, dialog);
    label->setWordWrap(true);
    label->setTextInteractionFlags(Qt::TextSelectableByMouse | Qt::TextSelectableByKeyboard | Qt::LinksAccessibleByMouse);
    layout->addWidget(label);
    dialog->show(); // use show() instead of exec()
}

void Parallelogram_calculator::saveFile()
{
    // Prompt the user to choose a file name and location
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt)"));

    // Open the file in write mode
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // If the file could not be opened, display an error message
       QMessageBox::warning(this, tr("Error"), tr("Could not save file "));
        return;
    }


    // Write the data to the file
    QTextStream out(&file);

    if(ui->stackedWidget->currentIndex() == 0)
    {
        out << tr("Area For Parallelogram") + "\n";
        out << tr("Base Value :   ") + ui->Area_base_input->text() + "\n";
        out << tr("Height Value:  ") + ui->Area_height_input->text() + "\n";
        out << tr("Formula:  ") + ui->Area_solutionFormula->text() + "\n";
        out << tr("Area Solution:  ") + ui->Area_solution2->text() + "\n";
        out << tr("Answer:  ") + ui->Area_answspot->text() + "\n";
    }

    else if(ui->stackedWidget->currentIndex() == 1)
    {
        out << tr("Perimeter For Parallelogram") + "\n";
        out << tr("Base Value :   ") + ui->P_base_input->text() + "\n";
        out << tr("Side Value :  ") + ui->P_side_input->text() + "\n";
        out << tr("Formula:  ") + ui->Permimeter_solutionFormula->text() + "\n";
        out << tr("Area Solution:  ") + ui->Perimeter_solution_2->text() + "\n";
        out << tr("Answer:  ") + ui->Perimeter_answspot->text() + "\n";

    }
    else if (ui->stackedWidget->currentIndex() == 2)
    {
        out << tr("Height For Parallelogram") + "\n";
        out << tr("Base Value :   ") + ui->H_base_input->text() + "\n";
        out << tr("Area Value :  ") + ui->H_area_input->text() + "\n";
        out << tr("Formula:  ") + ui->Height_solutionFormula->text() + "\n";
        out << tr("Area Solution:  ") + ui->Height_solution->text() + "\n";
        out << tr("Answer:  ") + ui->Height_answspot->text() + "\n";

    }
        file.close();

}


void Parallelogram_calculator::on_Area_Solve_Button_clicked()
{
    // Get the base and height values from the QLineEdit widgets
    double base = ui->Area_base_input->text().toDouble();
    double height = ui->Area_height_input->text().toDouble();

    // Calculate the area of the parallelogram using the formula
    double area = base * height;

    // Create a QString object that contains the formula with the substituted values
    QString formula = QString("A = %1 * %2 = %3").arg(base).arg(height).arg(area);

    // Display the formula in the first QLabel widget
    ui->Area_solution2->setText(formula);

    // Display the calculated area in the second QLabel widget
    ui->Area_answspot->setText(QString::number(area));
}


void Parallelogram_calculator::on_H_Solve_Button_clicked()
{
    // Get base and area values from QLineEdits
    double base = ui->H_base_input->text().toDouble();
    double area = ui->H_area_input->text().toDouble();

    // Calculate height using the formula for parallelogram
    double height = area / base;

    // Display the formula with the substituted values in a QLabel
    QString formula = "H =  " + QString::number(area) + " / " + QString::number(base) + " = " + QString::number(height);
    ui->Height_solution->setText(formula);

    // Display the calculated height in a different QLabel

    ui->Height_answspot->setText(QString::number(height));
}



void Parallelogram_calculator::on_P_Solve_Button_clicked()
{
    // Get the base and side values entered in the QLineEdit widgets
    double base = ui->P_base_input->text().toDouble();
    double side = ui->P_side_input->text().toDouble();

    // Calculate the perimeter of the parallelogram using the formula: P = 2*(base + side)
    double perimeter = 2*(base + side);

    // Display the formula with the substituted value from the QLineEdit widgets
    ui->Perimeter_solution_2->setText("P = 2*(" + QString::number(base) + " + " + QString::number(side) + ")");

    // Display the calculated perimeter in a different QLabel
    ui->Perimeter_answspot->setText(QString::number(perimeter));
}



void Parallelogram_calculator::on_actionNew_triggered()
{

       QWidget *newCalculator = new(Parallelogram_calculator); // create new QTextEdit object on the heap
       newCalculator->show(); // show the new text editor window

}

void Parallelogram_calculator::hideToolbar()
{   //sets the toolbar object to hide
    ui->toolBar->hide();
}

void Parallelogram_calculator::ViewToolbar()
{
    //sets the toolbar object to show
    ui->toolBar->show();
}





void Parallelogram_calculator::on_actionAbout_triggered()
{
   QMessageBox::about(this, tr("About Parallelogram Calculator"), tr("This is a simple Parallelogram Calculator created by Group 5."));
}



