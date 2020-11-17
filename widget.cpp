#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
        ui(new Ui::Widget),
            calculatorLogic(new CalculatorLogic(this))
{
    ui->setupUi(this);

    ui->Display->setText("0");

    connect(ui->pushButton0, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton1, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton2, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton3, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton4, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton5, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton6, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton7, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton8, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->pushButton9, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->clear, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->backspace, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->changeSign, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->plus, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->minus, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->divide, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->multiply, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->equality, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->sqrt, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(ui->period, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
    connect(calculatorLogic, SIGNAL(resultHistoryChanged(QString)), this, SLOT(onResultHistoryChanged()));
    connect(calculatorLogic, SIGNAL(resultChanged(QString)), this, SLOT(onResultChanged()));



}

Widget::~Widget()
{
    delete ui;
}

void Widget::onBtnClicked()
{
    QPushButton* button=(QPushButton*)sender();
    calculatorLogic->doCommand(button->text());

}
void Widget::onResultChanged()
{
    ui->Display->setText(calculatorLogic->getResult());
}
void Widget::onResultHistoryChanged()
{
    ui->history->setPlainText(calculatorLogic->getHistory());
}

