#include <QApplication>
#include <QPushButton>
#include "./ui_design.h"
#include "calculatormainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CalculatorMainWindow window(nullptr);
    Ui::MainWindow calculator;
    calculator.setupUi(&window);
    window.textEdit = calculator.textEdit;
    window.textEdit_2 = calculator.textEdit_2;
    window.textEdit_3 = calculator.textEdit_3;
    window.resize(480,640);
    window.show();
    return QApplication::exec();
}
