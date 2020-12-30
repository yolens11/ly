#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./treeview/treewidget.h"
#include "./dragview/dragview.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_tree_clicked()
{
    TreeWidget* tree = new TreeWidget();
    tree->show();
}

void MainWindow::on_pushButton_drag_clicked()
{
    DragView* drag = new DragView();
    drag->show();
}
