#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void insert(int data);
    bool search(int data);

private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;
};

#endif
