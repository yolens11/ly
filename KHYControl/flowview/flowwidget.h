#ifndef FLOWWIDGET_H
#define FLOWWIDGET_H

#include <QWidget>

namespace Ui {
class FlowWidget;
}

class FlowWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FlowWidget(QWidget *parent = nullptr);
    ~FlowWidget();

private:
    Ui::FlowWidget *ui;
};

#endif // FLOWWIDGET_H
