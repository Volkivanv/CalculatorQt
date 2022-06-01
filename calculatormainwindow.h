//
// Created by Ivan on 29.05.2022.
//

#ifndef CALCULATORQT_CALCULATORMAINWINDOW_H
#define CALCULATORQT_CALCULATORMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QTextEdit>
#include <string>




class CalculatorMainWindow : public QMainWindow{
Q_OBJECT
public:
    CalculatorMainWindow(QWidget* parent = nullptr):

    QMainWindow(parent){};

    QTextEdit *textEdit = nullptr;
    QTextEdit *textEdit_2 = nullptr;
    QTextEdit *textEdit_3 = nullptr;

public slots:
    void slotSum(){

        std::string sA = textEdit-> toMarkdown().toStdString();
        std::string sB = textEdit_2-> toMarkdown().toStdString();
        if(isNumber(sA) && isNumber(sB)) {
            double a = std::stod(sA);
            double b = std::stod(sB);
            textEdit_3 -> setText(std::to_string(a + b).c_str());
        }else {
            textEdit_3->setText("ERROR! Incorrect input!");
        }
    };
    void slotSubtract(){
        std::string sA = textEdit-> toMarkdown().toStdString();
        std::string sB = textEdit_2-> toMarkdown().toStdString();
        if(isNumber(sA) && isNumber(sB)) {
            double a = std::stod(sA);
            double b = std::stod(sB);
            textEdit_3 -> setText(std::to_string(a - b).c_str());
        }else {
            textEdit_3->setText("ERROR! Incorrect input!");
        }
    };
    void slotDivide(){
        double a;
        double b;
        std::string sA = textEdit-> toMarkdown().toStdString();
        std::string sB = textEdit_2-> toMarkdown().toStdString();
        if(isNumber(sA) && isNumber(sB)) {
            a = std::stod(sA);
            b = std::stod(sB);
            if(b!=0) {
                textEdit_3->setText(std::to_string(a / b).c_str());
            } else {
                textEdit_3->setText("ERROR! Division by zero!");
            }
        }else {
            textEdit_3->setText("ERROR! Incorrect input!");
        }

    };
    void slotMultiplicate(){
        std::string sA = textEdit-> toMarkdown().toStdString();
        std::string sB = textEdit_2-> toMarkdown().toStdString();
        if(isNumber(sA) && isNumber(sB)) {
            double a = std::stod(sA);
            double b = std::stod(sB);
            textEdit_3 -> setText(std::to_string(a * b).c_str());
        }else {
            textEdit_3->setText("ERROR! Incorrect input!");
        }
    };
private:
    bool isNumber(std::string &s) {
        int pointCount = 0;
/*
        for (int i = s.length()-1; i >=0; i--) {
            if (((s[i] < '0') || (s[i] > '9'))&&(i == s.length() - 1)) {
                s.pop_back();
            }
        }
*/
        for (int i = s.length()-1; i >=0; i--) {
            if (((s[i] == '\n')||(s[i] == '.')||(s[i] == ','))&&(i == s.length() - 1)) {
                s.pop_back();
            }
        }




        for (int i = s.length()-1; i >=0; i--) {
            if(s[i] == ',') s[i] ='.';

            if ((s[i] == '.') || (s[i] == '-')){

               if(s[i] == '.'){
                    pointCount++;
                    if(pointCount > 1) return false;
               }
               if((s[i] =='-')&&(i != 0)) {
                    return false;
               }

            } else if((s[i] < '0') || (s[i] > '9')) return false;
        }
        return true;
    }



};

#endif //CALCULATORQT_CALCULATORMAINWINDOW_H
