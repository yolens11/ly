#include "treewidget.h"
#include "ui_treewidget.h"
#include <QDebug>

TreeWidget::TreeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreeWidget)
{
    ui->setupUi(this);

    m_model = new TreeModel(ui->treeView);
    ui->treeView->setModel(m_model);
    QList<QVariant> datas;
    m_rootItem = new TreeItem(datas);
    m_model->setupModelData(m_rootItem);
    this->setAcceptDrops(true);

   // ui->treeView->setDragEnabled(true);
   // ui->treeView->setAcceptDrops(true);
   // ui->treeView->setDropIndicatorShown(true);
   // ui->treeView->setDragDropMode(QAbstractItemView::InternalMove);

    connect(ui->treeView, &QTreeView::pressed, this, &TreeWidget::onPressed);

}

TreeWidget::~TreeWidget()
{
    delete ui;
}

void TreeWidget::dragEnterEvent(QDragEnterEvent *event)
{
    QStringList formats = event->mimeData()->formats();
    qDebug() << "dragEnterEvent formats = " << formats;
    if (event->mimeData()->hasFormat("Node/NodePtr"))
        event->accept();
    else
        event->ignore();
}

void TreeWidget::dragLeaveEvent(QDragLeaveEvent *event)
{
    qDebug() << "dragLeaveEvent";
}


void TreeWidget::dragMoveEvent(QDragMoveEvent *event)
{
    QStringList formats = event->mimeData()->formats();
    qDebug() << "dragMoveEvent formats = " << formats;
    if (event->mimeData()->hasFormat("Node/NodePtr")) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else {
        event->ignore();
    }
}

void TreeWidget::dropEvent(QDropEvent *event)
{

    QStringList formats = event->mimeData()->formats();
    qDebug() << "dropEvent formats = " << formats;
    if (event->mimeData()->hasFormat("Node/NodePtr"))
    {
        QVariant varData = event->mimeData()->data("Node/NodePtr");
        QByteArray byteData = varData.toByteArray();
        QDataStream stream(&byteData, QIODevice::ReadWrite);
        qint64 node;
        stream >> (node);
        TreeItem* devNode = (TreeItem*)(node);

        //if (devNode)
        //    ui->lineEdit->setText(devNode->mText);

        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void TreeWidget::onPressed(const QModelIndex &index)
{

}
