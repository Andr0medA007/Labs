#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    char data;
    Node* prev = nullptr;
    Node* next = nullptr;
};
struct List {
    Node* hn = nullptr;
    Node* tn = nullptr;
};

void push_back(List& list, const char& data);
void push_front(List& list, const char& data);
void show(List& list);
void del_elem(List& list);
void del_first(List& list);
void del_last(List& list);
void del(List& list, char r);
void set(List& list, char r, int k);
void download(List& list);
void delete_list(List& list);
void take(List& list);

int main()
{
    List list;
    system("chcp 1251");
    char r;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r;
        push_back(list, r);
    }
    show(list);
    cout << "Введите ключ для удаления: " << endl;
    cin >> r;
    del(list, r);
    show(list);
    cout << "Перед каким значением вводить новые элементы: " << endl;
    cin >> r;
    cout << "Сколько элементов ввести перед заданным значением: " << endl;
    cin >> k;
    set(list, r, k);
    show(list);
    download(list);
    delete_list(list);
    take(list);
    show(list);
    return 0;
}

void push_back(List& list, const char& data) {
    Node* new_node = new Node;
    new_node->data = data;
    if (list.hn == nullptr) {
        list.hn = new_node;
        list.tn = new_node;
    }
    else {
        list.tn->next = new_node;
        new_node->prev = list.tn;
        list.tn = new_node;
    }
}
void push_front(List& list, const char& data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = list.hn;
    list.hn->prev = new_node;
    list.hn = new_node;
}
void show(List& list) {
    Node* currentNode = list.hn;
    while (currentNode != nullptr) {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
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
    while (currentNode->next != list.tn) {
        currentNode = currentNode->next;
    }
    currentNode->next = nullptr;
    delete list.tn;
    list.tn = currentNode;
}
void del_first(List& list) {
    if (list.hn == nullptr) {
        return;
    }
    Node* currentNode = list.hn;
    list.hn = currentNode->next;
    delete currentNode;
}
void del_elem(List&list) {
    if (list.hn == nullptr) {
        return;
    }
    Node* currentNode = list.hn;
    list.hn = currentNode->next;
    delete currentNode;
}
void del(List& list, char r) {
    Node* first = list.hn;
    Node* last = first->next;
    if (list.hn->data == r) {
        del_first(list);
        return;
    }
    if (list.tn->data == r) {
        del_last(list);
        return;
    }
    while (last && last->data != r) {
        last = last->next;
        first = first->next;
    }
    if (!last) {
        cout << "Такого элемента нет" << endl;
        return;
    }
    first->next = last->next;
    delete last;
}
void set(List& list, char r, int k){
    Node* first = list.hn;
    Node* last = first->next;
    if (list.hn->data == r) {
        for (int i = 0; i < k; i++) {
            char m;
            cout << "Что добавить: " << endl;
            cin >> m;
            push_front(list, m);
        }
    }
    while (last && last->data != r) {
        last = last->next;
        first = first->next;
    }
    if (last && last->data == r) {
        for (int i = 0; i < k; i++) {
            Node* new_node = new Node;
            char m;
            cout << "Что добавить: " << endl;
            cin >> m;
            first->next = new_node;
            new_node->data = m;
            new_node->prev = first;
            new_node->next= last;
            last->prev = new_node;
            first = new_node;
        }
    }
}
void download(List& list) {
    ofstream out;
    out.open("File.txt");
    if (out.is_open()) {
        Node* last = list.hn;
        while (last != nullptr) {
            out << last->data << endl;
            last = last->next;
        }
        delete last;
    }
}
void delete_list(List& list) {
    Node* first = list.hn;
    while (first)
    {
        Node* tmp = first;
        first = first->next;
        delete tmp;
    }
}
void take(List& list) {
    char r;
    ifstream in;
    in.open("File.txt");
    if (in.is_open()) {
        list.hn = nullptr;
        list.tn = nullptr;
        while (in.get(r)) {
            push_back(list, r);
        }
        in.close();
    }

}