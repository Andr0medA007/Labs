#include <iostream>
#include <fstream>
using namespace std;
char r;

struct Stack {
    char data;
    Stack* prev;
};
Stack* make_stack(int n);
void print(Stack* first);
char pop(Stack*& first);
Stack* push(Stack*& first, char r);
void download(Stack& stack);

int main()
{
    setlocale(LC_ALL, "Ru");
    int n, k = 0,j = 0;
    cout << "Количество элементов стека: " << endl;
    cin >> n;
    Stack* stack = make_stack(n);
    print(stack);
    cout << "Введите ключ удаления: " << endl;
    cin >> r;
    Stack* stack2 = make_stack(0);
    
    for (int i = 0; i < n; i++) {
        char del = pop(stack);
        if (del == r) {
            k++;
        }
        else {
            push(stack2, del);
        }
    }
    n = n - k;
    for (int i = 0; i < n; i++) {
        char del = pop(stack2);
        push(stack, del);
    }
    cout << "Стек после удаления: " << endl;
    print(stack);
    cout << "Количество элементов для добавления: " << endl;
    cin >> k;
    cout << "Перед каким элементом добавлять: " << endl;
    cin >> r;
    while (stack->data != r) {
        char del = pop(stack);
        push(stack2, del);
        j++;
    }
    cout << "Введите элементы: " << endl;
    for (int i = 0; i < k; i++) {
        cin >> r;
        push(stack, r);
    }
    for (int i = 0; i < n - j + 2;i++) {
        char del = pop(stack2);
        push(stack, del);
    }
    print(stack);
    return 0;
}

Stack* make_stack(int n) {
    if (n == 0) return 0;
    Stack* first;
    Stack* current;
    first = NULL;
    current = new Stack;
    cin >> r;
    current->data = r;
    current->prev = NULL;
    first = current;
    for (int i = 2; i <= n; i++) {
        Stack* m = new Stack;
        cin >> r;
        m->data = r;
        m->prev = first;
        first = m;
    }
    return first;
}
void print(Stack* first) {
    if (first == nullptr) cout << "Стек пустой" << endl;
    Stack* current = first;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;

}
char pop(Stack*& first) {
    Stack* cur = first;
    int k = 0;
    while (cur != NULL) {
        k++;
        cur = cur->prev;
    }
    cur = first;
    if (k == 1) {
        char t = first->data;
        delete cur;
        first = nullptr;
        return t;
    }
    else {
        Stack* t = cur->prev;
        char l = cur->data;
        first = t;
        delete cur;
        return l;
    }
}
Stack* push(Stack*& first, char r) {
    Stack* cur = new Stack;
    cur->data = r;
    cur->prev = first;
    first = cur;
    return first;
}
void download(Stack*& first) {
    ofstream out;
    out.open("File.txt");
    if (out.is_open()){
        while (first != nullptr) {
            out << first->data << endl;
            first = first->prev;
        }
    delete first;
    }
}