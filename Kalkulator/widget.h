#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "CalculatorLogic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void onBtnClicked();
    void onResultChanged();
    void onResultHistoryChanged();

private:
    Ui::Widget *ui;
    CalculatorLogic* calculatorLogic;
};
#endif // WIDGET_H
