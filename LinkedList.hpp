#ifndef LL_H
#define LL_H

class LinkedList {
    public:
        class Node {
            public:
                Node(int val);
                ~Node();

                Node* getNext() const;
                Node* getPrev() const;
                void setNext(Node* next);
                void setPrev(Node* next);

                int getVal();

            private:
                Node* next;
                Node* prev;
                int val;
        };

        LinkedList();
        ~LinkedList();
        
        void remove(int val);
        void printLinkedList();

        Node* addToFront(int val);
        Node* addToBack(int val);
        int getSize() const;

        Node* head;
        Node* tail;

    private:
        int size;
};

#endif