#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};
struct queue {
    int size;
    Node* hn;
    Node* tn;
};

void init_queue(queue& q, const char& value);
void new_queue(queue& q, int n);
void push(queue& q, const char& value);
void print(queue& q);
void pop(queue& q);
void del_key(queue& q, char r);
void insert(queue& q,int count, char r);

int main()
{
    system("chcp 1251");
    queue q;
    int n;
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
void push(queue& q, const char& value) {
    Node* new_node = new Node;
    q.size++;
    new_node->data = value;
    new_node->next = nullptr;
    q.tn->next = new_node;
    q.tn = new_node;
}
void print(queue& q) {
    Node* tmp = q.hn;
    while (tmp != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void pop(queue& q) {
    Node* tmp = q.hn;
    q.hn = q.hn->next;
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
    cur = q.hn;
    cur->data = q.hn->data;
    while (cur->data != r){
        push(q, q.hn->data);
        pop(q);
        k++;
    }
    for(int j = 0;j<count;j++){
        cout << "Введите элемент добавления: " << endl;
        cin >> r;
        push(q, r);
    }
    for (k; k <= q.size - count; k++) {
        push(q, q.hn->data);
        pop(q);
    }
}