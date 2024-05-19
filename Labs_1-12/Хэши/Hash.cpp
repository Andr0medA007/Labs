#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

const int M = 100;
const double A = M_PI_4;
int collisionCounter = 0;


struct Node {
    string key = "";
    string value = "";
    Node* next = nullptr;
    Node* prev = nullptr;
};
struct HashTable {
    Node* table[M];
    HashTable() {
        for (int i = 0; i < M; ++i) {
            table[i] = nullptr;
        }
    }
};

double mod1(double k);
int getHash(double k);
int getHash(string line);
bool add(HashTable& table, string key, string elem);
bool removeByKey(HashTable& table, string key);
bool removeByValue(HashTable& table, string elem);
Node* get(HashTable& table, string key);
void print(HashTable& table);
string generateFullName();
string correctStr(int n, int lenght);
string generateBirthday();
string generatePassportNum();
void write(HashTable& table);
void read(HashTable& table);

int main()
{
    system("chcp 1251");
    system("cls");
    srand(time(NULL));
    HashTable myTable;
    for (int i = 0; i < M; i++) {
        string Birthday = generateBirthday();
        string newHuman = generateFullName() + " | " + Birthday + " | " + generatePassportNum();
        add(myTable, Birthday, newHuman);
    }
    cout << "Создана Хэш-Таблица: " << endl;
    print(myTable);
    int existingInd = rand() % M;
    while (myTable.table[existingInd] == nullptr) {
        existingInd = rand() % M;
    }
    Node* randomHuman = myTable.table[existingInd];
    string keyToRemove = randomHuman->key;
    cout << "Удаление по ключу: '" << keyToRemove << "':" << endl;
    if (removeByKey(myTable, keyToRemove)) {
        cout << "Элемент с ключом: '" << keyToRemove << "' успешно удалён" << endl;
    }
    else {
        cout << "Элемент с ключом: '" << keyToRemove << "' не найден" << endl;
    }
    print(myTable);
    write(myTable);
    read(myTable);
    print(myTable);
    cout << "Количетсво коллизий: " << collisionCounter << endl;
}

double mod1(double k) {
    int intPart = static_cast<int>(k);
    return k - intPart;
}
int getHash(double k) {
    return static_cast<int>(M * mod1(k * A));
}
int getHash(string line) {
    int n = 0;
    for (int i = 0; i < line.size(); i++) {
        n += static_cast<int>(pow(line[i], 2) * M_2_SQRTPI + abs(line[i]) * M_SQRT1_2);
    }
    return getHash(abs(n));
}
bool add(HashTable& table, string key, string elem) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->value = elem;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    int hash = getHash(key);
    if (table.table[hash] == nullptr) {
        table.table[hash] = newNode;
        return true;
    }
    else {
        Node* current = table.table[hash];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
        collisionCounter++;
        return true;
    }
}
bool removeByKey(HashTable& table, string key) {
    int hash = getHash(key);
    Node* current = table.table[hash];
    while (current != nullptr) {
        if (current->key == key) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            else {
                table.table[hash] = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            delete current;
            return true;
        }
        current = current->next;
    }
    return false;
}
bool removeByValue(HashTable& table, string elem) {
    for (int i = 0; i < M; i++) {
        Node* current = table.table[i];
        while (current != nullptr) {
            if (current->value == elem) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                }
                else {
                    table.table[i] = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                delete current;
                return true;
            }
        current = current->next;
        }
        return false;
    }
}
Node* get(HashTable& table, string key) {
    int hash = getHash(key);
    Node* current = table.table[hash];
    while (current != nullptr) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
void print(HashTable& table) {
    for (int i = 0; i < M; i++) {
        Node* current = table.table[i];
        while (current != nullptr) {
            cout << "[" << current->key << ": " << current->value << "]\n";
            current = current->next;
        }
    }
    cout << endl;
}

string name[30] = { "Иван", "Андрей", "Антон", "Амин", "Роберт", "Георгий", "Борис", "Владислав", "Дмитрий", "Никита", "Данила", "Артем", "Парвиз", "Сергей", "Илья", "Григорий", "Артур", "Денис", "Алексей", "Александр", "Валерий", "Дамир", "Михаил", "Константин", "Николай", "Герман", "Иннокентий", "Богдан", "Станислав", "Сурман" };
string patronymic[30] = { "Иванович", "Андреевич", "Антонович", "Аминович", "Робертович", "Георгиевич", "Борисович", "Владиславович", "Дмитриевич", "Никитович","Данилович", "Артемович", "Парвизович", "Сергеевич", "Ильич", "Григорьевич", "Артурович", "Денисович", "Алексеевич", "Александрович", "Валерьевич", "Дамирович", "Михайлович", "Константинович", "Николаевич", "Германович", "Иннокентьевич", "Богданович", "Станиславович", "Сурманович" };
string surname[30] = { "Карпов", "Афанасьев", "Власов","Маслов","Исаков","Тихонов","Аксёнов","Гаврилов","Родионов","Котов","Горбунов","Кудряшов","Быков","Зуев","Третьяков","Савельев","Панов","Рыбаков","Суворов","Абрамов","Воронов","Мухин","Архипов","Трофимов","Мартынов","Емельянов","Горшков","Чернов","Овчинников","Селезнёв" };

string generateFullName() {
    return surname[rand() % 30] + ' ' + name[rand() % 30] + ' ' + patronymic[rand() % 30];
}
string correctStr(int n,int lenght){
    string strn = to_string(n);
    while (strn.size() < lenght) {
        strn = '0' + strn;
    }
    while (strn.size() > lenght) {
        strn.erase(0, 1);
    }
    return strn;
}
string generateBirthday() {
    return correctStr(rand() % 28 + 1, 2) + '.' + correctStr(rand() % 12 + 1, 2) + '.' + to_string(rand() % 67 + 1960);
}
string generatePassportNum() {
    return correctStr(rand() % 10000, 4) + ' ' + correctStr((rand() % 1000000 * 100 + rand()), 6);
}
void write(HashTable& table) {
    ofstream out;
    out.open("File.txt");
    if (out.is_open()) {
        for (int i = 0; i < M; i++) {
            Node* current = table.table[i];
            while (current != nullptr) {
                out  << current->key << endl << current->value << "\n";
                current = current->next;
            }
        }
    }
    out.close();
}
void read(HashTable& table) {
    ifstream in;
    in.open("File.txt");
    if (in.is_open()) {
        for (int i = 0; i < M; i++) {
            Node* current = table.table[i];
            while (current != nullptr) {
                string str;
                getline(in, str);
                current->key = str;
                getline(in, str);
                current->value = str;
                current = current->next;
            }
        }
    }
}