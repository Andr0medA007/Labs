#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <vector>
#include <string>

int IPK=0;
float SIPK = 0;
float FP = 8134.88;
float Prem = 0;
int Prem_rate = 15;
float kat;
int h;
QVector<QString> vec = {"Страховая", "Накопительная", "Государственная", "Социальная"};

float CalcSP(float IPK, int SIPK, int FP){
    return IPK * SIPK + FP+ Prem*Prem_rate;
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_inval->hide();
    ui->lineEdit_Inval->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{
    if(ui->comboBox->currentIndex()==0){
        ui->label->setText("Пожалуйста, выберите тип пенсионных выплат");
    }
    if(ui->checkBox_inv->isChecked() && ui->checkBox_inv->isChecked() && ui->checkBox_inv->isChecked()){
        ui->label->setText("Пожалуйста, выберите что-то одно");
    }
    if(ui->comboBox->currentIndex()==1 && ui->checkBox_old->isChecked()){
        ui->label->setText("Тип пенсионных выплат: " + vec[0]+ "\n" + "Размер пенсионных выплат: " + QString::number(CalcSP(IPK, SIPK, FP))+ " Рублей");
    }
    if(ui->comboBox->currentIndex()==1 && ui->checkBox_inv->isChecked()){
        ui->label->setText("Тип пенсионных выплат: " + vec[0]+ "\n" + "Размер пенсионных выплат: " + QString::number(CalcSP(IPK, SIPK, FP)+ 4805*kat) + " Рублей");
    }
    if(ui->comboBox->currentIndex()==1 && ui->checkBox_inv->isChecked()){
        ui->label->setText("Тип пенсионных выплат: " + vec[0]+ "\n" + "Размер пенсионных выплат: " + QString::number(15379)+ " Рублей");
    }
    if(ui->comboBox->currentIndex()==2){
        ui->label->setText("Тип пенсионных выплат: " + vec[0]+ "\n" + "Размер пенсионных выплат: " + QString::number(CalcSP(IPK, SIPK, FP)) + " Рублей");
    }
}

void MainWindow::on_lineEdit_IPK_textChanged(const QString &arg1)
{
    IPK = arg1.toInt();
}

void MainWindow::on_lineEdit_SIPK_textChanged(const QString &arg1)
{
    SIPK = arg1.toFloat();
}

void MainWindow::on_checkBox_inv_released()
{
    ui->lineEdit_Inval->hide();
    ui->label_inval->hide();
}


void MainWindow::on_checkBox_inv_clicked()
{
    ui->lineEdit_Inval->show();
    ui->label_inval->show();
    if(!ui->checkBox_inv->isChecked()){
        ui->lineEdit_Inval->hide();
        ui->label_inval->hide();
    }
}


void MainWindow::on_lineEdit__prem_textChanged(const QString &arg1)
{
Prem = arg1.toFloat();
}


void MainWindow::on_lineEdit_Inval_textChanged(const QString &arg1)
{
kat = arg1.toInt();
if(kat == 1){
    kat = 2;
}
else if(kat == 2){
    kat = 1;
}
else if(kat == 3){
    kat = 0.5;
}
else{
    kat = 0;
}
}


void MainWindow::on_checkBox_lost_pressed()
{
    ui->lineEdit_SIPK->show();
    ui->lineEdit_IPK->show();
    ui->lineEdit__prem->show();
    ui->label_IPK->show();
    ui->label_SIPK->show();
    ui->label_Prem->show();
    ui->label_YED->show();
    ui->label_YED_2->show();
    ui->label_YED_3->show();
    if(!ui->checkBox_lost->isChecked()){
            ui->lineEdit_SIPK->hide();
            ui->lineEdit_IPK->hide();
            ui->lineEdit__prem->hide();
            ui->label_IPK->hide();
            ui->label_SIPK->hide();
            ui->label_Prem->hide();
            ui->label_YED->hide();
            ui->label_YED_2->hide();
            ui->label_YED_3->hide();
}
}

