#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Tree.h"
#include <QGraphicsScene>

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
    void createNode();
    void on_PUSH_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    BinaryTree binaryTree;
    void drawNode(Node *node, int x, int y, int hSpacing);
    void drawTree();
    void deleteNode();
    void showInorder();
    void showPreorder();
    void showPostorder();
    QString vectorToString(const vector<int>&vec);

};
#endif // MAINWINDOW_H
