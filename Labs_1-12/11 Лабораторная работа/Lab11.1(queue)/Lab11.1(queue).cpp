#include <iostream>
#include <fstream>
using namespace std;

int n;

struct Node {
    char data;
    Node* prev;
};
struct queue {
    int size;
    Node* hn;
    Node* tn;
};

void init_queue(queue& q, const char& value);
void new_queue(queue& q, int n);
void push(queue& q, char value);
void print(queue& q);
void pop(queue& q);
void del_key(queue& q, char r);
void insert(queue& q,int count, char r);
void write(queue& q);
void del_queue(queue& q);
void get(queue& q);

int main()
{
    system("chcp 1251");
    system("cls");
    queue q;
    
    char r;
    do {
        cout << "Введите длину очереди: " << endl;
        cin >> n;
    } while (n <= 0);
    new_queue(q, n);
    print(q);
    cout << "Ключ для удаления: " << endl;
    cin >> r;
    del_key(q, r);
    cout << endl;
    print(q);
    cout << "Введите элемент перед которым нужно поставить новые: " << endl;
    cin >> r;
    cout << "Сколько элементов ввести: " << endl;
    int count;
    cin >> count;
    insert(q, count, r);
    print(q);
    write(q);
    del_queue(q);
    print(q);
    get(q);
    print(q);

}

void init_queue(queue& q, const char& value) {
    Node* new_node = new Node;
    new_node->data = value;
    q.hn = new_node;
    q.tn = new_node;
    q.size = 1;
}
void new_queue(queue& q, int n) {
    char r;
    cout << "Введите элемент: " << endl;
    cin >> r;
    init_queue(q, r);
    for (int i = 2; i <= n; i++) {
        cout << "Введите элемент: " << endl;
        cin >> r;
        push(q, r);
    }
}
void push(queue& q, char value) {
    Node* new_node = new Node;
    q.size++;
    new_node->data = value;
    new_node->prev = nullptr;
    q.tn->prev = new_node;
    q.tn = new_node;
}
void print(queue& q) {
    Node* tmp = q.hn;
    while (tmp != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}
void pop(queue& q) {
    Node* tmp = q.hn;
    q.hn = q.hn->prev;
    q.size--;
    delete tmp;
}
void del_key(queue& q, char r) {
    int i = 1;
    while (i <= q.size) {
        if (q.hn->data == r) {
            pop(q);
        }
        else {
            push(q, q.hn->data);
            pop(q);
            i++;
        }
    }
}
void insert(queue& q, int count,char r) {
    Node* cur = new Node;
    int k = 0;
    while (q.hn->data != r){
        push(q, q.hn->data);
        pop(q);
        k++;
    }
    for(int j = 0;j<count;j++){
        cout << "Введите элемент добавления: " << endl;
        cin >> r;
        push(q, r);
    }
    for (k; k < q.size - count ; k++) {
        push(q, q.hn->data);
        pop(q);
    }
}
void write(queue& q) {
    ofstream out;
    out.open("File.txt");
    
    if (out.is_open()) {
        while (q.hn != nullptr) {
            out << q.hn->data << endl;
            q.hn = q.hn->prev;
        }
        delete q.hn;
    }
}
void del_queue(queue& q) {
    while (q.hn != nullptr) {
        Node* cur = new Node;
        cur = q.hn;
        q.hn = q.hn->prev;
        delete cur;
    }
}
void get(queue& q) {
    ifstream in;
    in.open("File.txt");
    char r;
    Node* new_node = new Node;
    q.hn = new_node;
    q.tn = new_node;
    while(in.get(r)){
        push(q, r);
    }
    pop(q);
}