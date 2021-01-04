#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_tree_clicked();

    void on_pushButton_drag_clicked();

    void on_pushButton_splitter_clicked();

    void on_pushButton_dock_clicked();

    void on_pushButton_flow_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
