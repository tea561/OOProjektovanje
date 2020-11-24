#include "chartpointdialog.h"
#include "ui_chartpointdialog.h"

ChartPointDialog::ChartPointDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChartPointDialog)
{
    ui->setupUi(this);
}

ChartPointDialog::~ChartPointDialog()
{
    delete ui;
}

QString ChartPointDialog::getLabel()
{
    return ui->lineLabel->text();
}

float ChartPointDialog::getValue()
{
    return ui->lineValue->text().toFloat();
}
QColor ChartPointDialog::getColor()
{
    QColor c;
    c.setNamedColor(ui->lineColor->text());
    return c;
}

void ChartPointDialog::setLabel(QString label)
{
    ui->lineLabel->setText(label);

}

void ChartPointDialog::setValue(float value)
{
    ui->lineValue->setText(QString::number(value));
}

QColor ChartPointDialog::setColor(QColor color)
{
    ui->lineColor->setText(color.name());
}

void ChartPointDialog::on_buttonColor_clicked()
{
    QColorDialog colorDialog;
    if(colorDialog.exec()==QDialog::Accepted)
    {
        //dijalog se zatvorio sa OK
        QColor color=colorDialog.selectedColor();
        ui->lineColor->setText(color.name());
    }
}
