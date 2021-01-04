#ifndef DOCKWIDGET2_H
#define DOCKWIDGET2_H

#include <QDockWidget>

namespace Ui {
class DockWidget2;
}

class DockWidget2 : public QDockWidget
{
    Q_OBJECT

public:
    explicit DockWidget2(QWidget *parent = nullptr);
    ~DockWidget2();

private:
    Ui::DockWidget2 *ui;
};

#endif // DOCKWIDGET2_H
