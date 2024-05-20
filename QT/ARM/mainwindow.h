#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_2_clicked();
    //void on_lineEdit_2_returnPressed();
    void on_lineEdit_IPK_textChanged(const QString &arg1);
    void on_lineEdit_SIPK_textChanged(const QString &arg1);

    void on_checkBox_inv_released();

    void on_checkBox_inv_clicked();

    void on_lineEdit__prem_textChanged(const QString &arg1);

    void on_lineEdit_Inval_textChanged(const QString &arg1);

    void on_checkBox_lost_pressed();

    //void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
