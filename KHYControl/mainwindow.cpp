#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./treeview/treewidget.h"
#include "./dragview/dragview.h"
#include "./splitterview/splitterwidget.h"
#include "./dockview/dockwidget3.h"
#include "./flowview/flowwidget.h"
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

void MainWindow::on_pushButton_splitter_clicked()
{
    SplitterWidget* w = new SplitterWidget();
    w->show();
}

void MainWindow::on_pushButton_dock_clicked()
{
    DockWidget3* w = new DockWidget3();
    w->show();
}

void MainWindow::on_pushButton_flow_clicked()
{
    FlowWidget* w = new FlowWidget();
    w->show();
}
