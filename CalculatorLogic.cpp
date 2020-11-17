#include "CalculatorLogic.h"

CalculatorLogic::CalculatorLogic(QObject *parent) : QObject(parent)
{

}

void CalculatorLogic::doCommand(QString button)
{


    if(button=="+"|| button=="-" || button=="*" || button=="/")
      {

        if(op=="")
       {
            if(strNum=="")
            {
                strNum="0";
                history+="0";
            }

            history+=button;
            result=strNum;
            first=strNum;
            strNum="";
        }
        else
        {
            //za slucaj da se unese "11+-", treba da bude upamceno "11-"
            history.chop(1);
            history+=button;
        }
        op=button;
    }

    else if(button=="C")
    {

        strNum="";
        value=0.0;
        result=QString::number(value);

    }
    else if(button=="←")
    {
       if(!strNum.isEmpty())
       {
           strNum.chop(1);
           history.chop(1);
           result=strNum;

           ////////////
       }

    }
    else if(button=="±")
    {
        value=strNum.toDouble()*(-1);
        result=QString::number(value);

        history+="±"+result;


    }
    else if(button=="√")
    {
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
        if(!result.contains(".")) //ukoliko u broju vec ne postoji decimalna tacka
        {
            /*double value=strNum.toDouble();
            strNum=QString::number(value)+".";*/
            strNum+=button; //dodaje se tacka

        }
        result=strNum;
        history+=button;

    }
    else if(button=="=")
    {
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
                   history=result;
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
         emit resultHistoryChanged(history);
    }
    else
    {
        history+=button;
        //broj
        strNum+=button;
        result=strNum;
    }

    emit resultChanged(result);




}
