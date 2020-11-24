#ifndef CHARTPOINTDIALOG_H
#define CHARTPOINTDIALOG_H

#include <QDialog>
#include <QColorDialog>
namespace Ui {
class ChartPointDialog;
}

class ChartPointDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChartPointDialog(QWidget *parent = nullptr);
    ~ChartPointDialog();

    QString getLabel();
    float getValue();
    QColor getColor();

    void setLabel(QString label);
    void setValue(float value);
    QColor setColor(QColor color);

private slots:

    void on_buttonColor_clicked();

private:
    Ui::ChartPointDialog *ui;
};

#endif // CHARTPOINTDIALOG_H
