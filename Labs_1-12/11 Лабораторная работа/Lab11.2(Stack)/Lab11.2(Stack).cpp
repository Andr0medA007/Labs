#include <iostream>
#include <fstream>
using namespace std;
char r;
int n, k = 0;

struct Stack {
    char data;
    Stack* prev;
};
Stack* make_stack(int n);
void print(Stack* first);
char pop(Stack*& first); 
Stack* push(Stack*& first, char r);
Stack* send(Stack*& first);
Stack* del(Stack*& first);
Stack* revive_stack();

int main()
{
    setlocale(LC_ALL, "Ru");
    int j = 0;
    cout << "Количество элементов стека: " << endl;
    cin >> n;
    Stack* stack = make_stack(n);
    print(stack);
    cout << "Введите ключ удаления: " << endl;
    cin >> r;
    Stack* stack2 = make_stack(0);
    
    for (int i = 0; i < n; i++) {
        char del = pop(stack);
        if (del != r) {
            push(stack2, del);
        }
        else {
            k = k + 1;
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
    send(stack);
    del(stack);
    print(stack);
   
    Stack* stack3 = revive_stack();

    print(stack3);
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
        first = NULL;
        return t;
    }
    if (k>1) { 
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
Stack* send(Stack*& first) {
    ofstream out;
    out.open("File.txt");
    if (out.is_open()){
        while (first != NULL) {
            out << first->data << endl;
            first = first->prev;
        }
    delete first;
    }
    return 0;
}
Stack* del(Stack*& first) {
    Stack* cur = first;
    while (cur != NULL) {
        Stack* t = cur->prev;
        delete cur;
        cur = t;
    }
    return 0;
}
Stack* revive_stack() {
    if (n == 0) return 0;
    ifstream in;
    in.open("File.txt");
    Stack* first;
    Stack* current;
    first = NULL;
    current = new Stack;
    r = in.get();
    current->data = r;
    current->prev = NULL;
    first = current;
    for (int i = 2; i <= 3*n; i++) {
        Stack* m = new Stack;
        r = in.get();
        m->data = r;
        m->prev = first;
        first = m;
    }
    return first;
}