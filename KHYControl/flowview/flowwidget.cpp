#include "flowwidget.h"
#include "ui_flowwidget.h"
#include "flowlayout.h"
#include <QPushButton>
#include <QLabel>

FlowWidget::FlowWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlowWidget)
{
    ui->setupUi(this);

    FlowLayout *flowLayout = new FlowLayout;
        QPushButton*  teerer = new QPushButton(this);
        teerer->setText("q1w");
        flowLayout->addWidget(new QPushButton(tr("Short")));
        flowLayout->addWidget(new QPushButton(tr("Longer")));
        flowLayout->addWidget(new QPushButton(tr("Different text")));
        flowLayout->addWidget(new QLabel(tr("More text")));
        flowLayout->addWidget(new QPushButton(tr("Even longer button text")));
        flowLayout->addWidget(teerer);//这样添加不显示内容
        setLayout(flowLayout);
        setWindowTitle(tr("Flow Layout"));
}

FlowWidget::~FlowWidget()
{
    delete ui;
}
