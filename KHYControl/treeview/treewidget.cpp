#include "treewidget.h"
#include "ui_treewidget.h"

TreeWidget::TreeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreeWidget)
{
    ui->setupUi(this);

    m_model = new TreeModel;
    ui->treeView->setModel(m_model);
    QList<QVariant> datas;
    m_rootItem = new TreeItem(datas);
    m_model->setupModelData(m_rootItem);
    this->setAcceptDrops(true);
}

TreeWidget::~TreeWidget()
{
    delete ui;
}
