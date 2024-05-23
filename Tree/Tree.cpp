#include "Tree.h"
#include <iostream>

using namespace std;

void BinaryTree::inorderHelper(Node *node, std::vector<int> &result) {
    if (node != nullptr) {
        result.push_back(node->data);
        inorderHelper(node->left, result);
        inorderHelper(node->right, result);
    }
}

void BinaryTree::preorderHelper(Node *node, std::vector<int> &result) {
    if (node != nullptr) {
        preorderHelper(node->left, result);
        result.push_back(node->data);
        preorderHelper(node->right, result);
    }
}

void BinaryTree::postorderHelper(Node *node, std::vector<int> &result) {
    if (node != nullptr) {
        postorderHelper(node->left, result);
        postorderHelper(node->right, result);
        result.push_back(node->data);
    }
}

Node* BinaryTree::insert(Node *node, const int value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }
    return node;
}

Node* BinaryTree::deleteNode(Node *node, int value) {
    if (node == nullptr) return node;
    if (value < node->data) {
        node->left = deleteNode(node->left, value);
    } else if (value > node->data) {
        node->right = deleteNode(node->right, value);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}



Node * BinaryTree::minValueNode(Node *node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node * BinaryTree::search(Node *node, int value) {
    if (node == nullptr || node->data == value) {
        return node;
    }
    if (value < node->data) {
        return search(node->left, value);
    }
    return search(node->right, value);
}

void BinaryTree::deleteTree(Node *node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void BinaryTree::insert(const int value) {
    root = insert(root, value);
}

void BinaryTree::deleteValue(int value) {
    root = deleteNode(root, value);
}

bool BinaryTree::searchValue(int value) {
    return search(root, value) != nullptr;
}

Node * BinaryTree::getRoot() const {
    return root;
}

vector<int> BinaryTree::inorder() {
    vector<int> result;
    inorderHelper(root, result);
    return result;
}

vector<int> BinaryTree::preorder() {
    vector<int> result;
    preorderHelper(root, result);
    return result;
}

vector<int> BinaryTree::postorder() {
    vector<int> result;
    postorderHelper(root, result);
    return result;
}

BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::BinaryTree(Node *value) {
    root = value;
}
