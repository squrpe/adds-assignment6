#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    while(head != nullptr) {
        deleteFromFront();
    }
}

void LinkedList::printList() {
    Node* currNode = head; 

    while (currNode != nullptr) { 
        std::cout << currNode->data << std::endl; 
        currNode = currNode->link; 
    } 
    std::cout << std::endl; 
}

Node* LinkedList::traverse(unsigned int index) {
    unsigned int position = 0;
    Node* currNode = head; 

    while (currNode != nullptr && position < index) { 
        currNode = currNode->link; 
        position++;
    } 
    
    return currNode;
}

void LinkedList::insertAtPosition(int item, unsigned int index) {
    // if adding in front of the current head (including if the list is empty)
    if (index == 0) {
        head = new Node(item, head);
        return;
    }

    // if inserting between two nodes; i.e. [A, C] -> [A, B, C]
    Node *prevNode = traverse(index-1);

    // if inserting out of bounds, abort
    if (prevNode == nullptr) {
        return;
    }

    Node *newNode  = new Node(item, prevNode->link);
    prevNode->link = newNode;
}

void LinkedList::deleteFromFront() {
    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    head = head->link;
    delete temp;
}