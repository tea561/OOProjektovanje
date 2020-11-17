#ifndef CALCULATORLOGIC_H
#define CALCULATORLOGIC_H

#include <QObject>
#include <QtMath>

class CalculatorLogic : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorLogic(QObject *parent = nullptr);

    void doCommand(QString);

signals:
    void resultChanged(QString);
    void resultHistoryChanged(QString);

private:
    double value;
    double tempNum;
    bool decimalNum;


    QString op;
    QString strNum="";
    QString first="";

    QString result;
    QString history;

public:
    QString getResult() const { return result; };
    QString getHistory() const { return history; };
};

#endif // CALCULATORLOGIC_H
