#ifndef MAINWINDOW_FIRST_H
#define MAINWINDOW_FIRST_H

#include <QMainWindow>
#include <QVector>

extern "C" {
#include "../s21_smartcalc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow_first; }
QT_END_NAMESPACE

class mainwindow_first : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:



private:
    Ui::mainwindow_first *ui;
    mainwindow_first *credit_calc;
};
#endif // MAINWINDOW_FIRST_H
