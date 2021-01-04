#include "dockwidget.h"
#include "ui_dockwidget.h"

DockWidget::DockWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DockWidget)
{
    ui->setupUi(this);


}

DockWidget::~DockWidget()
{
    delete ui;
}
