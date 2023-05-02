#ifndef NODE_H
#define NODE_H

class Node {
    public:
        Node(int, Node*);

        int data;
        Node* link;
};

#endif