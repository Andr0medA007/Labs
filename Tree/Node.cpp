#include "Node.h"

Node::Node() {
    data = 0;
    left = nullptr;
    right = nullptr;
}

Node::Node(const int value) {
    data = value;
    left = nullptr;
    right = nullptr;
}
