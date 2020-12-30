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
protected:
    void dropEvent(QDropEvent *event);								//放下动作
    void dragEnterEvent(QDragEnterEvent *event);					//托到进入窗口动作
    void dragMoveEvent(QDragMoveEvent *event);						//拖着物体在窗口移动
    void dragLeaveEvent(QDragLeaveEvent *event);					//拖走了没有释放
public slots:
    void onPressed(const QModelIndex &index);
private:
    Ui::TreeWidget *ui;

    TreeModel* m_model;
    TreeItem* m_rootItem;
};

#endif // TREEWIDGET_H
