#include "binary_search_tree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    destroy(root);
}

void BinarySearchTree::destroy(Node* node) {
    if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

void BinarySearchTree::insert(int data) {
    insert(root, data);
}

void BinarySearchTree::insert(Node*& node, int data) {
    if (!node) {
        node = new Node{data, nullptr, nullptr};
    } else if (data < node->data) {
        insert(node->left, data);
    } else {
        insert(node->right, data);
    }
}

bool BinarySearchTree::search(int data) {
    return search(root, data);
}

bool BinarySearchTree::search(Node* node, int data) {
    if (!node) {
        return false;
    } else if (node->data == data) {
        return true;
    } else if (data < node->data) {
        return search(node->left, data);
    } else {
        return search(node->right, data);
    }
}
