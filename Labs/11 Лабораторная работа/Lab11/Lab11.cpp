#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* ptnn = nullptr;
};
struct List {
    Node* hn = nullptr;
    Node* tn = nullptr;
};

void pushBack(List& list, const char& data);
void pushFront(List& list, const char& data);
void show(List& list);
void del_last(List& list);
void del_first(List& list);
void del(List& list,char r);
void set(List& list, char r, int k);
void write(List& list);
void delete_list(List& list);
void give(List& list);

int main()
{
    List list;
    system("chcp 1251");
    char r;
    int n, k;
    cout << "Введите длину списка: " << endl;
    cin >>n;
    for (int i = 0; i < n; i++) {
        cin >> r;
        pushBack(list, r);
    }
    show(list);
    cout << "Введите ключ для удаления: " << endl;
    cin >> r;
    del(list,r);
    show(list);
    cout << "Перед каким значением вводить новые элементы: " << endl;
    cin >> r;
    cout << "Сколько элементов ввести перед заданным значением: " << endl;
    cin >> k;
    set(list, r, k);
    show(list);
    write(list);
    delete_list(list);
    give(list);
    show(list);
    return 0;
}

void pushBack(List& list, const char& data) {
    Node* new_node = new Node;
    new_node->data = data;
    if (list.hn == nullptr) {
        list.hn = new_node;
        list.tn = new_node;
        return;
    }
    else {
        list.tn->ptnn = new_node;
        list.tn = new_node;
    }
}
void pushFront(List& list, const char& data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->ptnn = list.hn;
    list.hn = new_node;
}
void show(List& list) {
    Node* currentNode = list.hn;
    while (currentNode != nullptr) {
        cout << currentNode->data << " ";
        currentNode = currentNode->ptnn;
    }
    cout << endl;
}
void del_last(List& list) {
    if (list.hn == nullptr) {
        return;
    }
    if (list.hn == list.tn) {
        del_first(list);
        return;
    }
    Node* currentNode = list.hn;
    while (currentNode->ptnn != list.tn) {
        currentNode = currentNode->ptnn;
    }
    currentNode->ptnn = nullptr;
    delete list.tn;
    list.tn = currentNode;
}
void del_first(List& list) {
    if (list.hn == nullptr) {
        return;
    }
    Node* currentNode = list.hn;
    list.hn = currentNode->ptnn;
    delete currentNode;
}
void del(List& list, char r) {
    Node* first = list.hn;
    Node* last = first->ptnn;
    if (list.hn->data == r) {
        del_first(list);
        return;
    }
    if (list.tn->data == r) {
        del_last(list);
        return;
    }
    while (last && last->data != r) {
        last = last->ptnn;
        first = first->ptnn;
    }
    if (!last) {
        cout << "Такого элемента нет" << endl;
        return;
    }
    first->ptnn = last->ptnn;
    delete last;
}
void set(List& list, char r, int k) {
    Node* first = list.hn;
    Node* last = first->ptnn;
    if (list.hn->data == r) {
        for (int i = 0; i < k; i++) {
            char m;
            cout << "Что добавить: " << endl;
            cin >> m;
            pushFront(list, m);
        }
    }
    while (last && last->data != r) {
        last = last->ptnn;
        first = first->ptnn;
    }
    if (last && last->data == r) {
        for (int i = 0; i < k; i++) {
            Node* new_node = new Node;
            char m;
            cout << "Что добавить: " << endl;
            cin >> m;
            first->ptnn = new_node;
            new_node->data = m;
            new_node->ptnn = last;
            first = new_node;
        }
    }
}
void write(List& list) {
    ofstream out;
    out.open("F1.txt");
    if (out.is_open()) {
        Node* last = list.hn;
        while (last != nullptr) {
            out << last->data << endl;
            last = last->ptnn;
        }
        delete last;
    }
}
void delete_list(List& list) {
    Node*first = list.hn;
    while (first)
    {
        Node* tmp = first;
        first = first->ptnn;
        delete tmp;
    }
}
void give(List& list) {
    char r;
    ifstream in;
    in.open("F1.txt");
    if (in.is_open()) {
        list.hn = nullptr;
        list.tn = nullptr;
        while (in.get(r)) {
            pushBack(list, r);
        }
        in.close();
    }
    
}