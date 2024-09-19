#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int data);
    bool search(int data);

private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };
    Node* root;

    void insert(Node*& node, int data);
    bool search(Node* node, int data);
    void destroy(Node* node);
};

#endif // BINARY_SEARCH_TREE_H
