#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include "treemodel.h"

namespace Ui {
class TreeWidget;
}

class TreeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TreeWidget(QWidget *parent = nullptr);
    ~TreeWidget();

private:
    Ui::TreeWidget *ui;

    TreeModel* m_model;
    TreeItem* m_rootItem;
};

#endif // TREEWIDGET_H
