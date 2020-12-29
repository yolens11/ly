#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include "treeitem.h"
#include <QMimeData>

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit TreeModel(QObject *parent = nullptr);
    ~TreeModel();

    void updateData();
    void setupModelData(TreeItem *parent);
private:

    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    //bool setData(const QModelIndex &index, const QVariant &value, int role);
    QMimeData*  mimeData(const QModelIndexList &indexes) const
    {
        QMimeData* mimeD = QAbstractItemModel::mimeData(indexes);				//先获取原始的mimeData;
    
    
        if (indexes.size() > 0)
        {
            QModelIndex index = indexes.at(0);
    
            TreeModel* node = (TreeModel*)index.internalPointer();			
            QByteArray encoded;
            QDataStream stream(&encoded, QIODevice::WriteOnly);
            stream << (qint64)(node);
            mimeD->setData("Node/NodePtr", encoded);							//将自己需要的数据 存入到MimeData中
        }
        else
            mimeD->setData("Node/NodePtr", "NULL");
    
        return mimeD;
        //mimeD->setData()
    }
private:
    TreeItem *rootItem;
signals:

public slots:
};

#endif // TREEMODEL_H
