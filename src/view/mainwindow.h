#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

extern "C" {
#include "../s21_smartcalc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_AC_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_dot_clicked();
    void on_pushButton_0_clicked();
    void on_pushButton_open_clicked();
    void on_pushButton_close_clicked();
    void on_pushButton_mod_clicked();
    void on_pushButton_plus_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_div_clicked();
    void on_pushButton_muilt_clicked();
    void on_pushButton_pow_clicked();
    void on_pushButton_cos_clicked();
    void on_pushButton_sin_clicked();
    void on_pushButton_tan_clicked();
    void on_pushButton_log_clicked();
    void on_pushButton_acos_clicked();
    void on_pushButton_asin_clicked();
    void on_pushButton_atan_clicked();
    void on_pushButton_ln_clicked();
    void on_pushButton_x_clicked();
    void on_pushButton_eq_clicked();
    void on_pushButton_sqrt_clicked();
    void on_pushButton_clicked();

    void on_pushButton_credit_calc_clicked();

private:
    Ui::MainWindow *ui;
    double Xmin = -10.0;
    double Xmax = 10.0;
    double Ymin = -10.0;
    double Ymax = 10.0;
};
#endif // MAINWINDOW_H
