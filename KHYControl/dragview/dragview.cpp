#include "dragview.h"
#include "ui_dragview.h"

DragView::DragView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DragView)
{
    ui->setupUi(this);
}

DragView::~DragView()
{
    delete ui;
}
