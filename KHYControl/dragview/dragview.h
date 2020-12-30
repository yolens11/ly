#ifndef DRAGVIEW_H
#define DRAGVIEW_H

#include <QWidget>

namespace Ui {
class DragView;
}

class DragView : public QWidget
{
    Q_OBJECT

public:
    explicit DragView(QWidget *parent = nullptr);
    ~DragView();

private:
    Ui::DragView *ui;
};

#endif // DRAGVIEW_H
