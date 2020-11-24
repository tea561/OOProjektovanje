#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      m_chartDoc(new ChartDoc())
{
    ui->setupUi(this);
    ui->centralwidget->ref(m_chartDoc);
    connect(m_chartDoc, SIGNAL(chartDataChanged()), ui->centralwidget, SLOT(onChartDataChanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionLoad_Chart_triggered()
{
     QString fileName=QFileDialog::getOpenFileName(this,this->windowTitle(), QDir::currentPath(),"Text Files (*.txt)");
     if(!fileName.isEmpty())
         m_chartDoc->loadChartFromFile(fileName);
     emit m_chartDoc->chartDataChanged();
}

void MainWindow::on_actionSave_Chart_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,this->windowTitle(), QDir::currentPath(),"Text Files (*.txt)");
    if(!fileName.isEmpty())
    {
       m_chartDoc->saveChartToFile(fileName);
    }
    else
    {
        on_actionSave_Chart_triggered();
    }
}
