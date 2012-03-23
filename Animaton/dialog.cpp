#include "dialog.h"
#include "ui_dialog.h"
#include "field.h"
#include "checkersscene.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new CheckersScene();

    scene->setSceneRect(0, 0, 500, 500);

    ui->graphicsView->setScene(scene);

    Field val;

    val.showField(scene);
}

Dialog::~Dialog()
{
    delete ui;
}




