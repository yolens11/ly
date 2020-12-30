#include "treemodel.h"
#include <QIcon>

TreeModel::TreeModel(QObject *parent):QAbstractItemModel(parent)
{
    rootItem=NULL;

    updateData();
}

TreeModel::~TreeModel()
{
    delete rootItem;
}

void TreeModel::updateData()
{
    // 废弃旧的模型数据
    if(rootItem)
    {
        delete rootItem;
        rootItem=NULL;
    }

    QList<QVariant> rootData;
    rootData<<"Tag";//<<"Type";

    rootItem=new TreeItem(rootData);
    setupModelData(rootItem);

    // 刷新模型
    //reset();
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // 添加图标
    if(role==Qt::DecorationRole&&index.column()==0)
            return QIcon("images/fold.png");

    // 显示节点数据值
    if(role==Qt::DisplayRole)
    {
        TreeItem *item=static_cast<TreeItem*>(index.internalPointer());
         return item->data(index.column());
    }
    else if (role==Qt::SizeHintRole)
    {

        return QSize(36, 35);
    }

    return QVariant();
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return 0;

    Qt::ItemFlags flag = QAbstractItemModel::flags(index);
    return flag | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;				//允许Model拖动，这个很重要
    //return Qt::ItemIsEnabled|Qt::ItemIsSelectable;
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation,int role) const
{
    if(orientation==Qt::Horizontal&&role==Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

QModelIndex TreeModel::index(int row, int column,const QModelIndex &parent) const
{

    if(!hasIndex(row,column,parent))
        return QModelIndex();

    TreeItem *parentItem;
    if(!parent.isValid())
    {
        parentItem=rootItem;
    }else
    {
        parentItem=static_cast<TreeItem*>(parent.internalPointer());
    }

    TreeItem *childItem=parentItem->child(row);
    if(childItem)
        return createIndex(row,column,childItem); // 展开树形,为子节点建立索引
    else
        return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if(!index.isValid())
        return QModelIndex();

    TreeItem *childItem=static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem=childItem->parent();

    // 顶层节点,直接返回空索引
    if(parentItem==rootItem)
        return QModelIndex();

    // 为父结点建立索引
    return createIndex(parentItem->row(),0,parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem;

    if(!parent.isValid())
        parentItem=rootItem;
    else
        parentItem=static_cast<TreeItem*>(parent.internalPointer());

    return parentItem->childCount(); // 返回父结点下子结点数目
}

int TreeModel::columnCount(const QModelIndex &parent ) const
{
    return rootItem->columnCount();
}
#include <QTreeView>
bool TreeModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{

    TreeItem *item1=static_cast<TreeItem*>(draggedIndex.internalPointer());
    TreeItem *item2=static_cast<TreeItem*>(parent.internalPointer());

    rootItem->remove(item1,item2);
    //beginResetModel();
    //endResetModel();
    beginMoveRows(draggedIndex, draggedIndex.row(), draggedIndex.row(), parent, parent.row());
    endMoveRows();

    return true;
}

QMimeData *TreeModel::mimeData(const QModelIndexList &indexes) const {
    // 记住被拖拽的 index
    TreeModel *self = const_cast<TreeModel*>(this);
    self->draggedIndex = indexes.size() > 0 ? indexes[0] : QModelIndex();

    return QAbstractItemModel::mimeData(indexes);
}

bool TreeModel::canDropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column,const QModelIndex &parent) const
{
    Q_UNUSED(data)
    Q_UNUSED(action)
    Q_UNUSED(row)

    TreeItem *item1=static_cast<TreeItem*>(draggedIndex.internalPointer());
    TreeItem *item2=static_cast<TreeItem*>(parent.internalPointer());
    if (item1 == nullptr || item2 == nullptr)
        return false;
    if (item1!=item2 && item1->parent() == item2->parent())
        return true;
    return false;
 /*   TreeItem *item1=static_cast<TreeItem*>(draggedIndex.internalPointer());
    TreeItem *item2=static_cast<TreeItem*>(parent.internalPointer());

    if (item2 == nullptr || item1 == nullptr)
        return false;
    if (item1->parent() == item2->parent())
        return true;
    return false;*/
    /*// 只允许拖放到第 0 列
    if (column > 0) {
        return false;
    } else if (parent.isValid() && parent.column() > 0) {
        return false;
    } else {
        return true;
    }*/
}

// 设置模型数据,构建包含10个根结点,每个根结点包含两个子节点的树形结构
void TreeModel::setupModelData(TreeItem *parent)
{
    for(int i=0;i<10;i++)
    {
        QList<QVariant> datas;
        datas<<QString("设备-%1").arg(i+1)<<QString("类型-%1").arg(i+1);

        // 主结点下挂两个子节点
        TreeItem *primary=new TreeItem(datas,parent);
        parent->appendChild(primary);

        for(int j=0;j<2;j++)
        {
            QList<QVariant> ds;
            ds<<QString("子设备-%1").arg(j+1)<<QString("子类型-%1").arg(j+1);

            primary->appendChild(new TreeItem(ds,primary));
        }
    }
}
