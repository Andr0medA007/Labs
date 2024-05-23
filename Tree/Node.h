#ifndef NODE_H
#define NODE_H

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node();
    Node( int value);
};

#endif // NODE_H
