#include "dockwidget2.h"
#include "ui_dockwidget2.h"


DockWidget2::DockWidget2(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::DockWidget2)
{
    ui->setupUi(this);


}

DockWidget2::~DockWidget2()
{
    delete ui;
}
