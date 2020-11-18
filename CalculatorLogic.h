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
    QString op;
    QString strNum="";
    QString first="";

    QString result;
    QString history;
    QString historyChanged;

public:
    QString getResult() const { return result; };
    QString getHistory() const { return historyChanged; };
};

#endif // CALCULATORLOGIC_H
