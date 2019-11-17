#pragma once

#include "Tree.h"
#include "TreeNode.h"
#include <vector>
#include <iostream>
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

    std::vector<T> traverseInOrder() override {//left, root, right
    //https://github.com/pdgetrf/UWB_CSS342_2019_Fall/blob/master/class8/tree/src/BinaryTree.h
        // homework, to be done iteratively
        LinkedStack<TreeNode<T> *> stack;
        TreeNode<T>* curr=root;
        std::vector<T> output;
        while(curr!=nullptr || !stack.isEmpty()) {

            // travel as left as possible
            while(curr!= nullptr){
                stack.push(curr);
                curr=curr->left;
            }

            // the most left node
            // this could also be the node in the middle
            curr=stack.peek();
            stack.pop();
            output.push_back(curr->val);

            // move to the right side
            curr=curr->right;
        }
        return output;
    }

    std::vector<T> traversePreOrder() override {
        // don't bother
    }

    std::vector<T> traversePostOrder() override {//iteratively using a stack
        // homework, to be done iteratively
        //left, right, root
        //https://www.techiedelight.com/postorder-tree-traversal-iterative-recursive/
        LinkedStack<TreeNode<T>*> stack;//og stack
        LinkedStack<TreeNode<T>*> temp;//temp stack to help reverse
        TreeNode<T>* curr=root;
        std::vector<T> output;

        if (root==nullptr) {
            return output;
        }
        stack.push(root);//push root since it's last, bottom of stack

        while(!stack.isEmpty()){
            curr=stack.peek();
            stack.pop();

            temp.push(curr);

            if(curr->left){
                stack.push(curr->left);
            }
            if(curr->right){
                stack.push(curr->right);
            }
        }
        while(!temp.isEmpty()){//reverses order
            curr=temp.peek();
            temp.pop();
            output.push_back(curr->val);
        }
        return output;

    }

    virtual ~BinaryTree() {//using delete function to delete connections
        // homework
        //deleteTree(root);//calls to do recursively
        //decided not to risk it and use the destructor you already made
        LinkedStack<TreeNode<T> *> stack;

        if (root == nullptr) {
            return;
        }

        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode<T> *node = stack.peek();
            stack.pop();

            delete node;//root

            if (node->left != nullptr) {//left
                stack.push(node->left);
            }

            if (node->right != nullptr) {//right
                stack.push(node->right);
            }

        }
    }

    TreeNode<T>* _LCA(TreeNode<T>* node, T value1, T value2) {
        if (node== nullptr) {
            return nullptr;
        }

        // check root
        if (node->val == value1 || node->val == value2) {
            return node;
        }

        // check both childrens
        TreeNode<T>* left = _LCA(node->left, value1, value2);
        TreeNode<T>* right = _LCA(node->right, value1, value2);

        if (left!=nullptr && right!=nullptr) {
            return node;
        }

        if (left==nullptr && right==nullptr) {
            return nullptr;
        }

        return left == nullptr ? right : left;
    }

    T LCA(T node1, T node2) {
        // homework
        TreeNode<T>* node = _LCA(root, node1, node2);
        return node == nullptr ? -1 : node->val;
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
