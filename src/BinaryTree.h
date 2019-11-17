#pragma once

#include "Tree.h"
#include "TreeNode.h"
#include <vector>
#include "LinkedStack.h"

template<class T>
class BinaryTree :  public Tree<T> {
private:
    TreeNode<T>* root;

    int height(TreeNode<T>* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }

    void deleteTree(TreeNode<T> *node) {//added helper
        if(node==nullptr){
            return;
        }
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    BinaryTree() : root(nullptr) {};

    BinaryTree(std::vector<T> &array) {
        // not implemented yet
    }

    BinaryTree(TreeNode<T>* root) : root(root) {
    }

    bool contains(T val) override {
        // not implemented yet
        return false;
    }

    std::vector<T> traverseInOrder() override {

        // homework, to be done iteratively
        left
        root
        right
        
    }

    std::vector<T> traversePreOrder() override {
        // don't bother
    }

    std::vector<T> traversePostOrder() override {//iteratively using a stack
        // homework, to be done iteratively
        Stack<TreeNode<T>> stack;//og stack
        stack.push(root);

        while(!stack.isEmpty()){
            ListNode<T> *curr=stack.top();
            stack.pop();
        }

    }

    virtual ~BinaryTree() {//using delete function to delete connections
        // homework
        deleteTree(root);//calls to do recursively
    }

    T LCA(T node1, T node2) {
        // homework
    }

    bool add(const T &) override {
        // not implemented yet
    }

    bool remove(const T &) override {
        // not implemented yet
    }

    int height() override {
        return height(root);
    }

};
