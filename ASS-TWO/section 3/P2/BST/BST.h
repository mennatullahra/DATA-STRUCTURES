//
// Created by abdel on 6/12/2021.
//

#ifndef BST_BST_H
#define BST_BST_H
#pragma once
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* right;
    Node* left;
};
class BST {
private:
    Node* root = nullptr;
    void displayPre(Node* temp) {
        if (!temp) { return; }
        cout << temp->data << " ";
        displayPre(temp->left);
        displayPre(temp->right);
    }
    void displayIn(Node* temp) {
        if (!temp) { return; }
        displayIn(temp->left);
        cout << temp->data << " ";
        displayIn(temp->right);
    }
    void displayPo(Node* temp) {
        if (!temp) { return; }
        displayPo(temp->left);
        displayPo(temp->right);
        cout << temp->data << " ";
    }
    int getMaxHelper(Node* temp) {
        if (temp->right == nullptr)
        {
            return temp->data;
        }
        else { return getMaxHelper(temp->right); }
    }
    Node* deleteNum(Node* root, int number) {
        if (!root) { return nullptr; }
        else if (number < root->data)
        {
            root->left = deleteNum(root->left, number);
        }
        else if (number > root->data)
        {
            root->right = deleteNum(root->right, number);
        }
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else {
                int max = this->getMaxHelper(root->left);
                root->data = max;
                root->left = deleteNum(root->left, max);
            }
        }
        return root;
    }
public:
    void insert(int data) {
        Node* newnode = new Node;
        newnode->data = data;
        newnode->left = nullptr;
        newnode->right = nullptr;
        if (!root) {
            root = newnode;
            return;
        }
        Node* temp = root;
        Node* ptr = nullptr;
        while (temp) {
            ptr = temp;
            if (data <= temp->data)
            {
                temp = temp->left;
            }
            else { temp = temp->right; }
        }
        if (data <= ptr->data)
        {
            ptr->left = newnode;
        }
        else { ptr->right = newnode; }
    }
    int getMax()
    {
        getMaxHelper(root);
    }
    void displayPreorder() {
        if (root) { displayPre(root); }
    }
    void displayInorder() {
        if (root) { displayIn(root); }
    }
    void displayPostorder() {
        if (root) { displayPo(root); }
    }
    void deleteNumber(int number)
    {
        root = deleteNum(root, number);
    }
};


#endif //BST_BST_H
