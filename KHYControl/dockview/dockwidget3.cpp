#include "dockwidget3.h"
#include "ui_dockwidget3.h"
#include <QTextEdit>
#include <QDockWidget>
#include <QLayout>

DockWidget3::DockWidget3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DockWidget3)
{
    ui->setupUi(this);



    setDockNestingEnabled(true);

    setWindowTitle(tr("DockWidget"));
        QTextEdit *text = new QTextEdit(this);
        text->setText(tr("main"));
        text->setAlignment(Qt::AlignCenter);
        //setCentralWidget(text);
        setCentralWidget(ui->tableWidget);

        QDockWidget *dock = new QDockWidget(tr("DockWindow1"),this);
        dock->setFeatures(QDockWidget::DockWidgetMovable); //指定停靠窗体的样式，此处为可移动
        dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea | Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);
        QTextEdit *text1 = new QTextEdit();
        text1->setText(tr("win1"));
        dock->setWidget(text1);
        addDockWidget(Qt::RightDockWidgetArea,dock);
        m_dockList.push_back(dock);

        dock = new QDockWidget(tr("DockWindow2"),this);
        dock->setFeatures(QDockWidget::NoDockWidgetFeatures); //没有相关的权限
        QTextEdit *text2 = new QTextEdit();
        text2->setText(tr("win2"));
        dock->setWidget(text2);
        addDockWidget(Qt::RightDockWidgetArea,dock);
        m_dockList.push_back(dock);

        dock = new QDockWidget(tr("DockWindow3"),this);
        dock->setFeatures(QDockWidget::AllDockWidgetFeatures); //具有全部特性
        QTextEdit *text3 = new QTextEdit();
        text3->setText(tr("win3"));
        dock->setWidget(text3);
        addDockWidget(Qt::RightDockWidgetArea,dock);
        m_dockList.push_back(dock);

        dock = new QDockWidget(tr("bt1"),this);
        dock->setFeatures(QDockWidget::NoDockWidgetFeatures); //没有相关的权限
        dock->setWidget(ui->pushButton_save);
        addDockWidget(Qt::RightDockWidgetArea,dock);
        m_dockList.push_back(dock);

        dock = new QDockWidget(tr("bt2"),this);
        dock->setFeatures(QDockWidget::NoDockWidgetFeatures); //没有相关的权限
        dock->setWidget(ui->pushButton_re);
        addDockWidget(Qt::RightDockWidgetArea,dock);
        m_dockList.push_back(dock);

}

DockWidget3::~DockWidget3()
{
    delete ui;
}
#include <QSettings>
#include <QByteArray>

void DockWidget3::writeSettings()
{
  /*  QSettings settings("Software Inc.","Icon Editor");
    settings.beginGroup("mainWindow");
    settings.setValue("size", size());
    settings.setValue("state", saveState());
    settings.endGroup();*/

    QByteArray k2 = saveState();
    m_array = k2;
    int kk = 0;
    kk = 2;
}
void DockWidget3::readSettings()
{
  /*  QSettings settings("Software Inc.","Icon Editor");
    settings.beginGroup("mainWindow");
    resize(settings.value("size").toSize());
    restoreState(settings.value("state").toByteArray());
    settings.endGroup();*/

    restoreState(m_array);
    QList<QDockWidget *> dwList = this->findChildren<QDockWidget*>();
     foreach (QDockWidget *dw, dwList) {
        restoreDockWidget(dw);
     }
}

void DockWidget3::on_pushButton_save_clicked()
{
    writeSettings();
}

void DockWidget3::on_pushButton_re_clicked()
{
    readSettings();
}
