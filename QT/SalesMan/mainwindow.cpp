#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <queue>
#include <QDebug>
#include <math.h>
#include <QGraphicsTextItem>
using namespace std;
int INF = INT_MAX;
double deg = 360;
int N;
int all_cost;
QVector<int> solution_list; //правильный порядок вершин для прохождения
QVector<QVector<int>>Matrix_new; //Матрица смежности
int wantDraw = 0; //флаг для рисования путей задачи Комивояжера
QVector<QPair<double,double>> cords;

struct Node { // ячейка дерева
    QVector<QPair<int, int>> path; // список всех предыдущих рёбер
    QVector < QVector<int> > reducedMatrix;
    int cost; // минимальное значение длины дороги для данной ячейки
    int vertex; // последняя пройденная вершина
    int level; // уровень дерева
};

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
void MainWindow::on_lineEdit_textChanged(const QString &arg1) // установка значения размера матрицы смежности
{
    N = arg1.toInt();
}


void MainWindow::on_pushButton_clicked() //создание и вывод матрицы смежности
{
    ui->tableWidget->setColumnCount(N);
    ui->tableWidget->setRowCount(N);
}

QVector<QVector<int>> MainWindow::on_pushButton_2_clicked() //Заполнение матрицы смежности из таблицы
{
    QVector<QVector<int>>Matrix(N,QVector<int>(N));
    for(int i =0; i<Matrix.size(); i++){
        Matrix[i][i] = -1;
    }
    for(int i =0; i < Matrix.size();i++){
        for(int j = 0; j< Matrix.size();j++){
            QTableWidgetItem *item = ui->tableWidget->item(i,j);
            if (NULL != item) {
               Matrix[i][j] = item->text().toInt();
            }
        }
    }
    for(int i =0; i < Matrix.size();i++){
        for(int j = 0; j< Matrix.size();j++){
            if(Matrix[i][j] == -1){
                Matrix[i][j] = INF;
            }
        }
    }
    Matrix_new = Matrix;
    qDebug()<<Matrix_new;
    qDebug()<<N;
    return Matrix_new;
}


// j - Номер конечного города, i - откуда идёт путешественник
Node* newNode(QVector < QVector<int> >& parentMatrix,  QVector<QPair<int, int>>& path, int level, int i, int j)
{
    Node* node = new Node;


    node->path = path;
    if (level != 0)
        node->path.push_back(qMakePair(i, j)); //добавление ребра в список

    node->reducedMatrix = parentMatrix;

    for (int k = 0; level != 0 && k < N; k++)
    {
        // замена всех городов из i на бесконечность для ограничения прохождения
        node->reducedMatrix[i][k] = INF;

        // установить входящие ребра в город j на бесконечность
        node->reducedMatrix[k][j] = INF;
    }

    for(int k =0; k< N; k++){ //вместо уменьшения редуцированной матрицы просто заполняем бесконечностью нужные ячейки
        node->reducedMatrix[j][0] = INF;
    }

    // установить количество посещённых на данный момент городов
    node->level = level;

    // текущий номер города
    node->vertex = j;

    return node;
}

void rowReduction(QVector < QVector<int> >& reducedMatrix, vector<int>& row)
{
    for (int i = 0; i < N; i++)
        row.push_back(INF);
    // row[i] содержит минимум в строке i
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (reducedMatrix[i][j] < row[i])
                row.at(i) = reducedMatrix[i][j];

    //  редукция строк
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (reducedMatrix[i][j] != INF && row[i] != INF)
                reducedMatrix[i][j] -= row[i];
}


// Функция уменьшения каждого столбца таким образом, чтобы в каждом столбце был хотя бы один ноль
void columnReduction(QVector < QVector<int> >& reducedMatrix, vector<int>& col)
{
    for (int i = 0; i < N; i++)
        col.push_back(INF);

    // col[j] содержит минимум в столбце j
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (reducedMatrix[i][j] < col[j])
                col.at(j) = reducedMatrix[i][j];

    // редукция столбцов
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (reducedMatrix[i][j] != INF && col[j] != INF)
                reducedMatrix[i][j] -= col[j];
}

// Функция для получения нижней границы пути, начинающегося с текущего минимального узла
int calculateCost(QVector < QVector<int> >& reducedMatrix)
{
    // общая длина = 0
    int cost = 0;

    vector<int> row;
    rowReduction(reducedMatrix, row);

    vector<int> col;
    columnReduction(reducedMatrix, col);

    // вычисление длины дороги
    for (int i = 0; i < N; i++) {
        if (row[i]!=INT_MAX){
            cost += row[i];
        }
        if (col[i] != INT_MAX) {
            cost += col[i];
        }
    }
    return cost;

}

// заполнение массива пройденных городов
void printPath(QVector<QPair<int, int>> const& list)
{
    for (int i = 0; i < list.size(); i++)
        solution_list.push_back(list[i].first); // только первое число, чтобы не было повторов
}
struct srav { // структура для сравнения двух узлов дерева расстояний
    bool operator()(const Node* left_node, const Node* right_node) const
    {
        return left_node->cost > right_node->cost;
    }
};


// основная функция для рекурсивного нахождения кратчайшего пути
int solve(QVector < QVector<int> >& mid_Matrix)
{
    // приоритетная очередь для хранения узлов дерева
    priority_queue<Node*, vector<Node*>, srav> pq;

    QVector<QPair<int, int>> v;

    // создание первого узла дерева(Корня) и дальнейший запуск рекурсии
    Node* root = newNode(mid_Matrix, v, 0, -1, 0);

    // получение нижней границы, начиная с корня
    root->cost = calculateCost(root->reducedMatrix);

    // добавление корня в список узлов;
    pq.push(root);

    // Находит активный узел с наименьшей стоимостью, добавляет его дочерние элементы в список узлов и удаляет их из списка
    while (!pq.empty())
    {
        // нахождение узла с наименьшей стоимостью
        Node* min = pq.top();

        // Найденный узел удаляется из списка узлов.
        pq.pop();

        // i - передаёт текущий номер города
        int i = min->vertex;

        // если все города посещены
        if (min->level == N - 1)
        {
            // возвращение в стартовый город
            min->path.push_back(qMakePair(i, 0));

            // вывод всех посещённых городов
            printPath(min->path);

            return min->cost;
        }

        // для каждого дочернего элемента создаётся ребро в дереве
        for (int j = 0; j < N; j++)
        {
            if (min->reducedMatrix[i][j] != INF)
            {
                // создание потомка и вычисление длины дорог через города
                Node* sprout = newNode(min->reducedMatrix, min->path, min->level + 1, i, j);

                // стоимость дочернего узла состоит из стоимости базового узла, "стоимости" ребра [i][j], нижней границы пути

                sprout->cost = min->cost + min->reducedMatrix[i][j] + calculateCost(sprout->reducedMatrix); //sprout - производный узел дерева

                // добавление дочернего элемента в список узлов
                pq.push(sprout);
            }
        }
        delete min; // узел больше не нужен, т.к. сохранён в массиве
    }
    return 0;
}





void MainWindow::paintEvent(QPaintEvent *event){ // перегрузка метода воспроизведения графа
if(wantDraw){
scene = new QGraphicsScene();
ui->graphicsView->setScene(scene);
Q_UNUSED(event);
QPainter painter(this);
QBrush brush;
QPen pen;
QFont font;
font.setPixelSize(18);
pen.setColor("Blue");
brush.setStyle(Qt::SolidPattern);
painter.setRenderHint(QPainter::Antialiasing);
painter.translate(300,220);
double R = 2 * M_PI / int(solution_list.size());
int radius = 50;
for(int i =0; i< int(solution_list.size()); i++){ // Вычисление координат по формулам и сохранение их в списке пар
    double x = cos(i*R) * 165;
    double y = sin(i*R) * 165;
    cords.push_back(qMakePair(x,y));
    scene->addEllipse(x,y,radius,radius,pen);
    QGraphicsTextItem *text = scene->addText(QString::number(i+1),font); // отрисовка всех вершин графа
    text->setPos(x+15,y+15);
}

for(int i =0; i<int(solution_list.size());i++){ // отрисовка всех рёбер графа
    for(int j = 0 ; j<int(solution_list.size()); j++){
        if(Matrix_new[i][j]!= 0 && Matrix_new[i][j]!= INF){
            double x1= cos(i*R)*140+25;
            double y1= sin(i*R)*140+25;
            double x2= cos(j*R)*140+25;
            double y2= sin(j*R)*140+25;
            scene->addLine(x1,y1,x2,y2);
        }
    }
}
wantDraw = 0; // прекращение отрисовки графа
}
}
void MainWindow::on_GraphButton_clicked()
{
    wantDraw = 1;
    QString out = "";
    int cost = solve(Matrix_new); // вычисление минимальной длины дороги
    all_cost = cost;
    qDebug() << Matrix_new;
    qDebug() << solution_list;
    for (int i = 0; i < solution_list.size()-1; i++) {
        out = out + QString::number(solution_list[i]+1) + " -> " + QString::number(solution_list[i+1]+1) + " ";
    }
    if(cost != 0){ //если пути не существует
        ui->out->setText(out);
        ui->out_2->setText(QString::number(cost));
    }
    else{
        ui->out_2->setText("Невозможно составить путь");
    }
}

void MainWindow::on_pushButton_3_clicked() //отрисовка ответа на задачу Коммивояжера
{
    if(all_cost!=0){
    QPainter painter(this);
    QBrush brush;
    QPen pen;
    pen.setColor("Blue");
    brush.setStyle(Qt::SolidPattern);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(300,220);
    pen.setColor("Red");
    for(int i =0; i<int(solution_list.size())-1;i++){
    double x1 = cords[solution_list[i]].first+25;
    double y1 = cords[solution_list[i]].second+25;
    double x2 = cords[solution_list[i+1]].first+25;
    double y2 = cords[solution_list[i+1]].second+25;
    scene->addLine(x1,y1,x2,y2,pen);
    }
    qDebug() << solution_list;
    qDebug() << cords;
    }
}



