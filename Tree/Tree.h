#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <vector>

using namespace std;


class BinaryTree {
    Node* root;

    // Прямой метод обхода
    void inorderHelper(Node* node, std::vector<int>& result);
    // Симметричный метод обхода
    void preorderHelper(Node* node, std::vector<int>& result);
    // Обратный метод обхода
    void postorderHelper(Node* node, std::vector<int>& result);

    Node* insert(Node* node, int value);
    Node* deleteNode(Node* node, int value);
    Node* minValueNode(Node* node);
    Node* search(Node* node, int value);
    void deleteTree(Node* node);



public:
    void insert(int value);
    void deleteValue(int value);
    bool searchValue(int value);
    Node* getRoot() const;

    // Прямой обход
    vector<int> inorder();
    // Симметричный обход
    vector<int> preorder();
    // Обратный обход
    vector<int> postorder();

    BinaryTree();
    explicit BinaryTree(Node* value);

};

#endif // TREE_H
