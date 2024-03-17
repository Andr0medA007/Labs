#include <iostream>
using namespace std;
const int pole = 8; // Размер.

int board[pole][pole];
int res_count = 0; // Количество решений.

// Функция showBoard() - отображает доску.
void showBoard(){
    for (int i = 0; i < pole; i++){
        for (int j = 0; j < pole; j++){
            if (board[i][j]) { cout << "[Q]"; } // Если в клетке 1, то ставится ферзь
            else { cout << "[ ]"; } // Если 0 то пустая клетка
        }
        cout << endl;
    }
}

// Функция tryQueen() - проверяет нет ли уже установленных ферзей,
// по вертикали, диагоналям.
bool tryQueen(int a, int b){ // a - cтрока, b - клеткa
    for (int i = 0; i < a; ++i){
        if (board[i][b]){ // Если на одной вертикали будет ферзь, вернёт 0
            return false;
        }
    }
    for (int i = 1; i <= a && b - i >= 0; ++i){ // Проверка диагонали y = -x
        if (board[a - i][b - i]){
            return false;
        }
    }
    for (int i = 1; i <= a && b + i < pole; i++){ // Проверка диагонали y = x
        if (board[a - i][b + i]){
            return false;
        }
    }
    return true; // Если ферзю ничего не угрожает, возвращает 1
}

//Функция setQueen() - пробует найти результаты решений.
void setQueen(int x){ //  x - номер очередной строки в которую нужно поставить очередного ферзя.
    if (x == pole){
        showBoard();
        cout << "Result #" << ++res_count << endl<<endl;
    }
    for (int i = 0; i < pole; i++){
        // Здесь проверяем, что если поставим в board[x][i] ферзя (единицу),
        // то он будет единственным в этой строке, столбце и диагоналях.
        if (tryQueen(x, i)){ // Если в клетке нет угрожающих ферзей
            board[x][i] = 1; // Ставим ферзя
            setQueen(x + 1); // Смотрим следующие строки
            board[x][i] = 0; // Если неудачно, то убираем ферзя
        }
    }
}

int main()
{
    setQueen(0);
    return 0;
}