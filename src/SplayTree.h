#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include <iostream>
#include <memory>

template <typename T>
class SplayTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

    Node* rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    Node* splay(Node* root, const T& key) {
        if (!root || root->data == key)
            return root;

        
        if (key < root->data) {
            if (!root->left) return root;

            
            if (key < root->left->data) {
                root->left->left = splay(root->left->left, key);
                root = rightRotate(root);
            }
            
            else if (key > root->left->data) {
                root->left->right = splay(root->left->right, key);
                if (root->left->right)
                    root->left = leftRotate(root->left);
            }

            return (root->left) ? rightRotate(root) : root;
        } 
        else {
            if (!root->right) return root;

            
            if (key < root->right->data) {
                root->right->left = splay(root->right->left, key);
                if (root->right->left)
                    root->right = rightRotate(root->right);
            }
            
            else if (key > root->right->data) {
                root->right->right = splay(root->right->right, key);
                root = leftRotate(root);
            }

            return (root->right) ? leftRotate(root) : root;
        }
    }

    Node* insert(Node* root, const T& key) {
        if (!root)
            return new Node(key);

        root = splay(root, key);

        if (key == root->data)
            return root;

        Node* newNode = new Node(key);

        if (key < root->data) {
            newNode->right = root;
            newNode->left = root->left;
            root->left = nullptr;
        } else {
            newNode->left = root;
            newNode->right = root->right;
            root->right = nullptr;
        }

        return newNode;
    }

    Node* deleteNode(Node* root, const T& key) {
        if (!root) return nullptr;

        root = splay(root, key);

        if (key != root->data)
            return root;

        Node* temp;
        if (!root->left) {
            temp = root->right;
        } else {
            temp = splay(root->left, key);
            temp->right = root->right;
        }

        delete root;
        return temp;
    }

    Node* find(Node* root, const T& key) {
        return splay(root, key);
    }

public:
    void insert(const T& key) { root = insert(root, key); }
    void remove(const T& key) { root = deleteNode(root, key); }
    T* search(const T& key) {
        root = find(root, key);
        if (root && root->data == key)
            return &root->data;
        return nullptr;
    }
};

#endif