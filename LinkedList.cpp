#include "LinkedList.h"
#include <iostream>
#include <limits>

//a1802741

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(int* array, int len) {
    head = nullptr;

    for (int i = len - 1; i >= 0; i--) {
        insertPosition(0, array[i]);
    }
}

LinkedList::~LinkedList() {
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->link;
        delete current;
        current = next;
    }

    head = nullptr;
}

void LinkedList::insertPosition(int pos, int newNum) {
    Node* newNode = new Node(newNum, nullptr);

    if (head == nullptr) {
        head = newNode;
    }
    else if (pos <= 1) {
        newNode->link = head;
        head = newNode;
    }
    else {
        Node* current = head;

        int count = 1;

            while (current->link != nullptr && count < pos - 1) {
                current = current->link;
                count++;
            }

        
        newNode->link = current->link;
        current->link = newNode;
    }
}

bool LinkedList::deletePosition(int pos) {

    if (pos < 1 || head == nullptr) {
        return false;
    }

    Node* current = head;
    Node* previous = nullptr;

    if (pos == 1) {
        head = head->link;
    }
    else {
        for (int i = 1; i < pos && current != nullptr; i++) {
            previous = current;
            current = current->link;
        }
        if (current == nullptr) {
            return false;
        }
        previous->link = current->link;
    }

    delete current;
    return true;
}

int LinkedList::get(int pos) {

    if (head == nullptr) {
        return std::numeric_limits<int>::max();
    }

    Node* current = head;

    for (int i = 0; i < pos && current != nullptr; i++) {
        current = current->link;
    }

    if (current == nullptr) {
        return std::numeric_limits<int>::max();
    }

    return current->data;
}

int LinkedList::search(int target) {

    if (head == nullptr) {
        return -1;
    }


    Node* current = head;

    int pos = 0;

    while (current != nullptr && current->data != target) {
        current = current->link;
        pos++;
    }

    if (current == nullptr) {
        return -1;
    }

    return pos;
}

void LinkedList::printList() {

    if (head == nullptr) {
        return;
    }

    std::cout << "[";

    Node* current = head;

    while (current->link != nullptr) {
        std::cout << current->data << " ";
        current = current->link;
    }
    std::cout << current->data;

    std::cout << "]" << std::endl;
};