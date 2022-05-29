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

        double a = std::stod(textEdit->toMarkdown().toStdString());
        textEdit->setText(std::to_string(a).c_str());
        double b = std::stod(textEdit_2->toMarkdown().toStdString());
        textEdit_2->setText(std::to_string(b).c_str());
        textEdit_3->setText(std::to_string(a+b).c_str());
    };
    void slotSubtract(){
        double a = std::stod(textEdit->toMarkdown().toStdString());
        textEdit->setText(std::to_string(a).c_str());
        double b = std::stod(textEdit_2->toMarkdown().toStdString());
        textEdit_2->setText(std::to_string(b).c_str());
        textEdit_3->setText(std::to_string(a - b).c_str());
    };
    void slotDivide(){
        double a = std::stod(textEdit->toMarkdown().toStdString());
        textEdit->setText(std::to_string(a).c_str());
        double b = std::stod(textEdit_2->toMarkdown().toStdString());
        textEdit_2->setText(std::to_string(b).c_str());
        if(b!=0) {
            textEdit_3->setText(std::to_string(a / b).c_str());
        } else {
            textEdit_3->setText("ERROR!");
        }
    };
    void slotMultiplicate(){
        double a = std::stod(textEdit->toMarkdown().toStdString());
        textEdit->setText(std::to_string(a).c_str());
        double b = std::stod(textEdit_2->toMarkdown().toStdString());
        textEdit_2->setText(std::to_string(b).c_str());
        textEdit_3->setText(std::to_string(a*b).c_str());
    };



};

#endif //CALCULATORQT_CALCULATORMAINWINDOW_H
