#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chartdoc.h"

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
    void on_actionLoad_Chart_triggered();
    void on_actionSave_Chart_triggered();

private:
    Ui::MainWindow *ui;
    ChartDoc* m_chartDoc;
};
#endif // MAINWINDOW_H
