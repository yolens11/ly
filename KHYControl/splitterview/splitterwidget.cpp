#include "splitterwidget.h"
#include "ui_splitterwidget.h"

#include <QApplication>
#include <QSplitter>
#include <QTextCodec>
#include <QTextEdit>
#include <QObject>
#include <QPushButton>
QTextEdit* g_textMiddle = nullptr;
SplitterWidget::SplitterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SplitterWidget)
{
    ui->setupUi(this);


        QSplitter *splitterMain = new QSplitter(Qt::Horizontal, 0); //新建主分割窗口，水平分割
        QTextEdit *textLeft = new QTextEdit(QObject::tr("left"),splitterMain);
        textLeft->setMinimumSize(10,10);
        textLeft->setAlignment(Qt::AlignCenter);

        QSplitter *splitterRight = new QSplitter(Qt::Vertical, splitterMain);   //右分割窗口，并以主分割窗口作为父窗口
        splitterRight->setOpaqueResize(false);

        QTextEdit *textUp = new QTextEdit(QObject::tr("top"),splitterRight);
        textUp->setMinimumSize(10,10);
        textUp->setAlignment(Qt::AlignCenter);

        QTextEdit *textMiddle = new QTextEdit(QObject::tr("mid"),splitterRight);
        g_textMiddle = textMiddle;
        textMiddle->setMinimumSize(10,10);
        textMiddle->setAlignment(Qt::AlignCenter);

        QTextEdit *textBottom = new QTextEdit(QObject::tr("底部部件"),splitterRight);
        textBottom->setMinimumSize(10,10);
        textBottom->setAlignment(Qt::AlignCenter);

      //  splitterMain->setStretchFactor(1,0);
        splitterMain->setWindowTitle(QObject::tr("分割窗口"));
        splitterMain->show();

}

SplitterWidget::~SplitterWidget()
{
    delete ui;
}

void SplitterWidget::on_pushButton_clicked()
{
    static int i = 0;
    i++;
    if (i%2 == 0)
    {
        g_textMiddle->show();
    }
    else
    {
        g_textMiddle->hide();
    }
}
