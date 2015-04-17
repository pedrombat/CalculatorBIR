#ifndef INTERFACE_H
#define INTERFACE_H

#include <QApplication>
#include <QMainWindow>



int open_interface(int argc, char *argv[]);

namespace Ui {
class CalculatorInterface;
}



class CalculatorInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalculatorInterface(QWidget *parent = 0);
    ~CalculatorInterface();

    void EraseLCDAfterError();

private slots:

    void on_Button_0_clicked();
    void on_Button_1_clicked();
    void on_Button_2_clicked();
    void on_Button_3_clicked();
    void on_Button_4_clicked();
    void on_Button_5_clicked();
    void on_Button_6_clicked();
    void on_Button_7_clicked();
    void on_Button_8_clicked();
    void on_Button_9_clicked();
    void on_Button_AC_clicked();
    void on_Button_Dot_clicked();
    void on_Button_Plus_clicked();
    void on_Button_Minus_clicked();
    void on_Button_Times_clicked();
    void on_Button_Split_clicked();
    void on_Button_OpenBracket_clicked();
    void on_Button_CloseBracket_clicked();
    void on_Button_Backspace_clicked();
    void on_Button_Equal_clicked();

private:
    Ui::CalculatorInterface *ui;
};

#endif // INTERFACE_H
