#include "LinkedList.hpp"
#include <iostream>

LinkedList::Node::Node(int val) : val(val), next(nullptr), prev(nullptr) {};
LinkedList::Node::~Node() {};

LinkedList::Node* LinkedList::Node::getNext() const {
    return next;
}

LinkedList::Node* LinkedList::Node::getPrev() const {
    return prev;
}

void LinkedList::Node::setNext(Node* next) {
    this->next = next;
}

void LinkedList::Node::setPrev(Node* prev) {
    this->prev = prev;
}

int LinkedList::Node::getVal() {
    return val;
}

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {};

LinkedList::~LinkedList() {
    Node* curr = this->head;
    
    while (curr) {
        Node* next = curr->getNext();
        delete curr;
        curr = next;
    }
};

LinkedList::Node* LinkedList::addToFront(int val) {
    Node* newNode = new Node(val);
    size++;
    if (!head) {
        newNode->setNext(NULL);
        newNode->setPrev(NULL);
        head = newNode;
        tail = newNode;
        return newNode;
    }
    newNode->setNext(head);
    head->setPrev(newNode);
    head = newNode;
    return head;
}

LinkedList::Node* LinkedList::addToBack(int val) {
    Node* newNode = new Node(val);
    size++;
    if (!tail) {
        newNode->setNext(NULL);
        newNode->setPrev(NULL);
        head = newNode;
        tail = newNode;
        return newNode;
    }
    newNode->setPrev(tail);
    tail->setNext(newNode);
    tail = newNode;
    return tail;
}

void LinkedList::remove(int val) {
    Node* curr = this->head;
    
    if (!curr) {
        return;
    }

    while (curr) {
        if (curr->getVal() == val) {
            if (curr->getPrev() && curr->getNext()) {
                curr->getPrev()->setNext(curr->getNext());
                curr->getNext()->setPrev(curr->getPrev());
                Node* del = curr;
                curr = curr->getNext();
                size--;
                delete del;
            } else if (curr->getNext()) {
                this->head = curr->getNext();
                Node* del = head->getPrev();
                this->head->setPrev(nullptr);
                curr = head;
                size--;
                delete del;
            } else if (curr->getPrev()) {
                this->tail = curr->getPrev();
                Node* del = tail->getNext();
                this->tail->setNext(nullptr);
                delete del;
                size--;
                return;
            }
        } else {
            curr = curr->getNext();
        }
    }
}

void LinkedList::printLinkedList() {
    Node* curr = this->head;
    
    while (curr) {
        std::cout << curr->getVal() << " ";
        curr = curr->getNext();
    }

    std::cout << std::endl;
}

int LinkedList::getSize() const {
    return size;
}

int LinkedList::find(int vertex) {
    Node* curr = this->head;
    while (curr) {
        if (curr->getVal() == vertex) {
            return vertex;
        }
        curr = curr->getNext();
    }
    return 0;
}