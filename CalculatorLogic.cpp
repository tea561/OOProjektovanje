#include "CalculatorLogic.h"

CalculatorLogic::CalculatorLogic(QObject *parent) : QObject(parent)
{

}

void CalculatorLogic::doCommand(QString button)
{


    if(button=="+"|| button=="-" || button=="*" || button=="/")
      {

        if(op=="") //prvi put se unosi znak za operaciju
       {
            if(strNum=="" && result=="")
            {
                //ukoliko se unosi operacija bez prvog operanda, prvi operand je 0
                strNum="0";
                history+="0";
            }
            if(strNum=="" && result!="")
            {
                //ukoliko se operacija nadovezuje na prethodni rezultat
                strNum=result;
                history+=result;
            }

            history+=button;
            result=strNum;
            first=strNum;
            strNum="";
        }
        else if(op!="" && strNum=="")
        {
            //za slucaj da se unese "11+-", treba da bude upamceno "11-"
            history.chop(1);
            history+=button;
        }
        else
        {
            history+=button;
            //nadovezivanje operacija
            if(op=="+")
            {
                double t=first.toDouble()+strNum.toDouble();
                first=QString::number(t);

            }
            else if(op=="-")
            {
                double t=first.toDouble()-strNum.toDouble();
                first=QString::number(t);

            }
            else if(op=="*")
            {
                double t=first.toDouble()*strNum.toDouble();
                first=QString::number(t);

            }
            else if(op=="/")
            {
                double t=first.toDouble()/strNum.toDouble();
                first=QString::number(t);

            }
            strNum="";
        }
        op=button;
    }

    else if(button=="C")
    {

        strNum="";
        first="";
        op="";
        result="";
        history="";



    }
    else if(button=="←")
    {
       if(!strNum.isEmpty())
       {
           strNum.chop(1);
           history.chop(1);
           result=strNum;
       }

    }
    else if(button=="±")
    {
        if(strNum=="")
        {
            strNum=result;
            history+=strNum;
        }
        history.chop(strNum.length()); //iz istorije se brise broj ciji se znak menja
        double value=strNum.toDouble()*(-1);
        result=QString::number(value);
        strNum=result;

        history+=result;


    }
    else if(button=="√")
    {
            if(strNum=="" && result=="")
            {
                strNum="0";
                history+=strNum;

            }
            else if(first=="" && result!="")
            {
                history="";
            }
            else if(result!="")
            {
                strNum=result;
                if(history=="")
                {
                   history+=strNum;
                }
            }

            history.chop(strNum.length()); //broj ciji se koren trazi
            history+=button+strNum;
            double sqRoot=qSqrt(strNum.toDouble());

            result=QString::number(sqRoot);
            strNum=result;

    }
    else if(button==".")
    {
        if(strNum.isEmpty())
        {
            //ako prvo pritisne "." dodaje se ispred 0
            strNum="0";
            history+="0";

        }
        if(!strNum.contains(".")) //ukoliko u broju vec ne postoji decimalna tacka
        {

            strNum+=button; //dodaje se tacka
            history+=button;

        }
        result=strNum;


    }
    else if(button=="=")
    {
        if(strNum=="")
        {
            return;
        }
        history+=button;
        if(op=="")
        {
           //ako korisnik unese samo jedan broj i pritisne jednako
           //npr 23=23
           result=strNum;
           history+=result+"\n";
           strNum="";
        }
        if(op!="" && !first.isEmpty())
        {

            if(op=="+")
            {
               double t=first.toDouble()+strNum.toDouble();
               result=QString::number(t);

            }
            else if(op=="-")
            {
               double t=first.toDouble()-strNum.toDouble();
               result=QString::number(t);
            }
            else if(op=="*")
            {
               double t=first.toDouble()*strNum.toDouble();
               result=QString::number(t);

            }
            else if(op=="/")
            {
                if(strNum.toDouble()==0.0)
                {
                   result="NAN";

                }
                else
                {
                    double t=first.toDouble()/strNum.toDouble();
                    result=QString::number(t);
                }

            }
            history+=result + "\n";
            strNum="";
            op="";



        }
         historyChanged+=history;
         history="";
         emit resultHistoryChanged(historyChanged);
    }
    else
    {
        //broj
        history+=button;
        strNum+=button;
        result=strNum;
    }

    emit resultChanged(result);




}
