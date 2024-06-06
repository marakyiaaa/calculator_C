#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "iostream"
#include "cstring"
#include "string.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->show_str->clear();
}


void MainWindow::on_pushButton_1_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"1");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"2");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"3");
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"4");
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"5");
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"6");
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"7");
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"8");
    }
}

void MainWindow::on_pushButton_9_clicked()
{
      if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"9");
    }
}

void MainWindow::on_pushButton_dot_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+".");
    }
}

void MainWindow::on_pushButton_0_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"0");
    }
}

void MainWindow::on_pushButton_open_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"(");
    }
}

void MainWindow::on_pushButton_close_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+")");
    }
}

void MainWindow::on_pushButton_mod_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"mod(");
    }
}

void MainWindow::on_pushButton_plus_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"+");
    }
}

void MainWindow::on_pushButton_minus_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"-");
    }
}

void MainWindow::on_pushButton_div_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"/");
    }
}

void MainWindow::on_pushButton_muilt_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"*");
    }
}

void MainWindow::on_pushButton_pow_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"^");
    }
}

void MainWindow::on_pushButton_cos_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"cos(");
    }
}

void MainWindow::on_pushButton_sin_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"sin(");
    }
}

void MainWindow::on_pushButton_tan_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"tan(");
    }
}

void MainWindow::on_pushButton_log_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"log(");
    }
}

void MainWindow::on_pushButton_acos_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"ACOS(");
    }
}

void MainWindow::on_pushButton_asin_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"ASIN(");
    }
}

void MainWindow::on_pushButton_atan_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"ATAN(");
    }
}

void MainWindow::on_pushButton_ln_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"ln(");
    }
}

void MainWindow::on_pushButton_x_clicked()
{
     if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
        ui->show_str->setText(ui->show_str->text()+"x");
    }
}

void MainWindow::on_pushButton_sqrt_clicked()
{
    if(ui->show_str->text() != "ERROR" && ui->show_str->text() != "nan" && ui->show_str->text() != "inf") {
       ui->show_str->setText(ui->show_str->text()+"sqrt(");
   }
}

void MainWindow::on_pushButton_eq_clicked()

{
    QString text_label = ui->show_str->text();
    int i = 0;
    if(text_label != "ERROR" && text_label != "nan" && text_label != "inf"){
        QByteArray text_label_in_byte = text_label.toLatin1();
        char *str_label = text_label_in_byte.data();
        STACK *stack = initStack(stack);
        char output[255] ={0};
        double x = ui->box_for_x->value();
        if((i = convert_to_rpn(str_label, &stack,output, x)) == 0){
            pointers *queue= NULL;
            queue = str_to_queue(output);
            char *result = calculate(stack,queue);
            ui->show_str->setText(result);
        }else{
               ui->show_str->setText("ERROR");
        }
    }
    else{
        ui->show_str->setText("");
    }

}

void MainWindow::on_pushButton_clicked()
{
    double new_Xmax = Xmax;
    double new_Xmin = Xmin;
    double new_Ymax = Ymax;
    double new_Ymin = Ymin;
    double h = 0.1;
    if (ui->doubleSpinBox_Ymin->value() != 0 || ui->doubleSpinBox_Ymax->value() != 0 ||
        ui->doubleSpinBox_Xmin->value() != 0 || ui->doubleSpinBox_Xmax->value() != 0) {
        new_Xmax = ui->doubleSpinBox_Xmax->value();
        new_Xmin = ui->doubleSpinBox_Xmin->value();
        new_Ymax = ui->doubleSpinBox_Ymax->value();
        new_Ymin = ui->doubleSpinBox_Ymin->value();
    }
    QVector<double> x, y;
    STACK *stack = initStack(stack);
    QString text_label = ui->show_str->text();
    QByteArray text_label_in_byte = text_label.toLatin1();
    char *str_label = text_label_in_byte.data();
      int flag_one = validate_expression(str_label);
      int flag_two = check_dot_error(str_label);
      int flag_three = check_staples(str_label);

    if(*str_label && str_label!= "ERROR" && str_label!= "nan" && str_label!= "inf" && !flag_one && !flag_two && !flag_three){
        double y_val = 0;
        for(double i = new_Xmin; i < new_Xmax; i += h){
            char output[255] ={0};
            int error = convert_to_rpn(str_label, &stack,output, i);
            pointers *queue= NULL;
            queue = str_to_queue(output);
            char *result = calculate(stack, queue);
            QString num = QString::fromLatin1(result);
            y_val = num.toDouble();
            if(error == 1){
                ui->show_str->setText("ERROR");
            }
            else{
                x.push_back(i);
                y.push_back(y_val);
            }
            num.clear();
        }
    }
    ui->widget_graph->addGraph();
    ui->widget_graph->graph(0)->setData(x, y);
    ui->widget_graph->xAxis->setLabel("x");
    ui->widget_graph->yAxis->setLabel("y");

    ui->widget_graph->xAxis->setRange(new_Xmin, new_Xmax);
    ui->widget_graph->yAxis->setRange(new_Ymin, new_Ymax);

    ui->widget_graph->replot();
    ui->widget_graph->update();

    x.clear();
    y.clear();
}

void MainWindow::on_pushButton_credit_calc_clicked()
{
    if (ui->radioButton_ann->isChecked() == false && ui->radioButton_diff->isChecked() == false){}

    else if (ui->radioButton_ann->isChecked() == true && ui->radioButton_diff->isChecked() == false ){
        double summa = ui->doubleSpinBox_summa->value();
        double stake = ui->doubleSpinBox_proc_stavka->value();
        int period = ui->spinBox_srok->value();

        double monthly_pay = 0.0;
        double over_pay = 0.0;
        double total_pay = 0.0;
        credit_calc_ann(summa, period, stake, &monthly_pay, &over_pay, &total_pay);

        QString str_monthly_pay = QString::number(monthly_pay);
        ui->label_one->setText(str_monthly_pay);

        QString str_over_pay = QString::number(over_pay);
        ui->label_nachic_proc->setText(str_over_pay);

        QString str_total_pay = QString::number(total_pay);
        ui->label_total->setText(str_total_pay);


    }
    else {
        double summa = ui->doubleSpinBox_summa->value();
        double stake = ui->doubleSpinBox_proc_stavka->value();
        int period = ui->spinBox_srok->value();

        double over_pay = 0.0;
        double total_pay = 0.0;
        double first_pay = 0.0;
        double last_pay = 0.0;

        credit_diff(summa, period, stake, &over_pay, &total_pay, &first_pay, &last_pay);

        QString str_first = QString::number(first_pay);
        QString str_last = QString::number(last_pay);
          ui->label_one->setText(str_first + " - " + str_last);


        QString str_over_pay = QString::number(over_pay);
        ui->label_nachic_proc->setText(str_over_pay);

        QString str_total_pay = QString::number(total_pay);
        ui->label_total->setText(str_total_pay);
    }
}

