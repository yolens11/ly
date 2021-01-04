#ifndef SPLITTERWIDGET_H
#define SPLITTERWIDGET_H

#include <QWidget>

namespace Ui {
class SplitterWidget;
}

class SplitterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SplitterWidget(QWidget *parent = nullptr);
    ~SplitterWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SplitterWidget *ui;
};

#endif // SPLITTERWIDGET_H
