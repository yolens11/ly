#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>
#include <QStandardItemModel>

class MyModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit MyModel(QStandardItemModel *parent = 0);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QMimeData *mimeData(const QModelIndexList &indexes) const;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
    QStringList mimeTypes() const;

signals:

public slots:

private:
    int m_rowCount;
    bool m_bAdd = false;
};


#endif // MYMODEL_H
