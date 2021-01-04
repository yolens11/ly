#ifndef DOCKWIDGET3_H
#define DOCKWIDGET3_H

#include <QMainWindow>

namespace Ui {
class DockWidget3;
}

class DockWidget3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit DockWidget3(QWidget *parent = nullptr);
    ~DockWidget3();
private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_re_clicked();

private:
    void writeSettings();
    void readSettings();
private:
    Ui::DockWidget3 *ui;

    QByteArray m_array;
    QList<QDockWidget*> m_dockList;
};

#endif // DOCKWIDGET3_H
