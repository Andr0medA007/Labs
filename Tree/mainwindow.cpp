#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsScene"
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include <QDebug>

bool ok;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Подготавливаем сцену и вид для визуализации графа
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    // Настройка главного окна
    setWindowTitle("Qt Binary Tree");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::drawTree() {
    scene->clear(); // Очистка сцены перед рисованием
    drawNode(binaryTree.getRoot(), 200, 30, 100); // Начальные координаты и расстояние между узлами
}

void MainWindow::on_PUSH_clicked()
{
    createNode();
}

void MainWindow::createNode() {
    QString line = ui->lineEdit->text();
    int value = line.toInt();
    binaryTree.insert(value);
    drawTree();
    qDebug() << value;
}

void MainWindow::deleteNode() {
    QString line = ui->lineEdit->text();
    int value = line.toInt();
    binaryTree.deleteValue(value);
    drawTree();
}

void MainWindow::drawNode(Node *node, int x, int y, int hSpacing) {
    if (!node) return;

    scene->addEllipse(x, y, 30, 30);
    QGraphicsTextItem *text = scene->addText(QString::number(node->data));
    text->setPos(x + 5, y+2);

    if (node->left) {
        scene->addLine(x+15, y+30, x-hSpacing+15, y+60, QPen(Qt::black));
        drawNode(node->left, x-hSpacing, y+60, hSpacing/2);
    }
    if (node->right) {
        scene->addLine(x+15, y+30, x+hSpacing+15, y+60, QPen(Qt::black));
        drawNode(node->right, x+hSpacing, y+60, hSpacing/2);
    }
}
void MainWindow::showInorder() {
    vector<int> result = binaryTree.inorder();
    ui->outLine->setText(vectorToString(result));
}

void MainWindow::showPreorder() {
    vector<int> result = binaryTree.preorder();
    ui->outLine->setText(vectorToString(result));
}

void MainWindow::showPostorder() {
    vector<int> result = binaryTree.postorder();
    ui->outLine->setText(vectorToString(result));
}

QString MainWindow::vectorToString(const vector<int>& vec) {
    QString res;
    for (int val : vec) {
        res += QString::number(val) + " ";
    }
    return res.trimmed();
}


void MainWindow::on_pushButton_2_clicked()
{
    deleteNode();
}


void MainWindow::on_pushButton_3_clicked()
{
    showInorder();
}


void MainWindow::on_pushButton_4_clicked()
{
    showPreorder();
}


void MainWindow::on_pushButton_5_clicked()
{
    showPostorder();
}

