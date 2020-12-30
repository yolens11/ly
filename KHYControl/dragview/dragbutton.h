#ifndef DRAGBUTTON_H
#define DRAGBUTTON_H

#include <QObject>
#include <QPushButton>

class DragButton : public QPushButton
{
    Q_OBJECT
public:
    explicit DragButton(QWidget *parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private:
    QPoint pressPoint;
signals:

public slots:
};

#endif // DRAGBUTTON_H
