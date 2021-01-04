#include "mymodel.h"

#include <QDebug>
#include <QMimeData>
#include <QModelIndexList>

MyModel::MyModel(QStandardItemModel *parent)
    : QStandardItemModel(parent)
{
    m_rowCount=0;
}

Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    flags = flags | Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled;
    return flags;
}

QMimeData *MyModel::mimeData(const QModelIndexList &indexes) const
{
    if (indexes.count() <= 0)
        return 0;

    QMimeData *data = new QMimeData;
    data->setData("drag","鼠标拖拽");
    data->setData("name",item(indexes.at(0).row(),0)->text().toLocal8Bit());
    data->setData("score",item(indexes.at(0).row(),1)->text().toLocal8Bit());

    return data;
}

bool MyModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{

        QString st=QString::fromLocal8Bit(data->data("name"));
        QString st1=QString::fromLocal8Bit(data->data("score"));

        this->setItem(m_rowCount,0,new QStandardItem(st));
        this->setItem(m_rowCount,1,new QStandardItem(st1));
        m_rowCount++;


    return true;
}

QStringList MyModel::mimeTypes() const
{
    QStringList types;
    types << "drag";
    return types;
}

