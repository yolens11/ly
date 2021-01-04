#include "dragview.h"
#include "ui_dragview.h"
#include "mymodel.h"

DragView::DragView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DragView)
{
    ui->setupUi(this);

    MyModel* m_model1=new MyModel;
    m_model1->setColumnCount(2);
    m_model1->setRowCount(4);
    m_model1->setItem(0,0,new QStandardItem("球球"));
    m_model1->setItem(0,1,new QStandardItem("99"));
    m_model1->setItem(1,0,new QStandardItem("213"));
    m_model1->setItem(1,1, new QStandardItem("59"));
   // m_model1->setItem(1,0,new QStandardItem("猪小明"));
   // m_model1->setItem(1,1,new QStandardItem("59"));
    m_model1->setItem(2,0,new QStandardItem("锅盖"));
    m_model1->setItem(2,1,new QStandardItem("111"));
    m_model1->setItem(3,0,new QStandardItem("闰土"));
    m_model1->setItem(3,1,new QStandardItem("999"));
    m_model1->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    m_model1->setHorizontalHeaderItem(1,new QStandardItem("成绩"));
    ui->treeView->setModel(m_model1);
    ui->treeView->setDragDropMode(QAbstractItemView::DragOnly);


    MyModel* m_model2=new MyModel;
    m_model2->setColumnCount(2);
    m_model2->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    m_model2->setHorizontalHeaderItem(1,new QStandardItem("成绩"));
    ui->treeView_2->setModel(m_model2);
    ui->treeView_2->setDragDropMode(QAbstractItemView::DropOnly);

    MyModel* m_model3 = new MyModel;
    m_model3->setColumnCount(2);
    m_model3->setColumnCount(2);
    m_model3->setRowCount(4);
    m_model3->setItem(0,0,new QStandardItem("球球"));
    m_model3->setItem(0,1,new QStandardItem("99"));
    m_model3->setItem(1,0,new QStandardItem("213"));
    m_model3->setItem(1,1, new QStandardItem("59"));
    m_model3->setHorizontalHeaderItem(0,new QStandardItem("姓名"));
    m_model3->setHorizontalHeaderItem(1,new QStandardItem("成绩"));
    ui->tableView->setModel(m_model3);
    ui->tableView->setDragDropMode(QAbstractItemView::DragDrop);
}

DragView::~DragView()
{
    delete ui;
}
