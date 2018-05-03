//
// Created by Dell on 30/04/2018.
//

#ifndef DSWET1_AVLTREE_H
#define DSWET1_AVLTREE_H

#include <iostream>
using std::cout;

class TreeExceptions {
};
class FAILURE_TREE: public TreeExceptions {
};
class ALLOCATION_ERROR_TREE: public TreeExceptions {
};


template<class T>
class Node {
    T data;
    int height;
    Node* father;
    Node* left, *right;

public:
    Node (const T& data){
        this->data = data;
        this->height = 0;
        this->father = nullptr;
        this->right = nullptr;
        this->left = nullptr;
    }

    void setData (const T& data){
        if (this == nullptr){
            return;
        }
        this->data = data;
    }

    void setHeight (const int height){
        if (this == nullptr){
            return;
        }
        this->height = height;
    }

    void setFather (Node<T>* father){
        if (this == nullptr){
            return;
        }
        this->father = father;
    }

    void setRight (Node<T>* right){
        if (this == nullptr){
            return;
        }
        this->right = right;
    }

    void setLeft (Node<T>* left){
        if (this == nullptr){
            return;
        }
        this->left = left;
    }


    T& getData (){
        return this->data;
    }

    int getHeight (){
        return this->height;
    }


    Node<T>* getFather() {
        if (this == nullptr) {
            return nullptr;
        }
        return this->father;
    }

    Node<T>* getRight() {
        if (this == nullptr) {
            return nullptr;
        }
        return this->right;
    }

    Node<T>* getLeft() {
        if (this == nullptr) {
            return nullptr;
        }
        return this->left;
    }

};

template <class T, class compKey>
class AvlTree {
    Node<T> *root;

public:
    AvlTree() {
        this->root = nullptr;
    }

    Node<T> *getRoot() {
        return this->root;
    }

    void setRoot(Node<T> *new_root) {
        if (new_root == nullptr)
            return;
        this->root = new_root;
    }


    T find(T data, Node<T> *current) {
        if (current == nullptr) {
            throw FAILURE_TREE();
            //  return nullptr;                         // maybe null is not good
        } else {
            compKey compare;
            if (compare(data, current->getData()) == 0) {
                return current->getData();
            } else {
                if (compare(data, current->getData()) > 0) {
                    return find(data, current->getRight());
                } else {
                    return find(data, current->getLeft());
                }
            }


            //RETURN NOT FOUND
        }
    }

    bool contain(T data){
    try {
         (this->find(data, this->getRoot()))  ;

    }
        catch (TreeExceptions&){
            return false;
        }
        return true;
    }

    int max (Node<T>* left, Node<T>* right){
        if (left == nullptr){
            return right->getHeight();
        }
        if (right == nullptr){
            return left->getHeight();
        }
        return left->getHeight() > right->getHeight() ? left->getHeight() : right->getHeight();
    }



    void insert (T data, Node<T>* current){
        //what about failure
        compKey compare;
        if (current == nullptr){
            Node<T>* new_node = new Node<T>(data);
            this->setRoot(new_node);
        }
        else {
            if (compare(data, current->getData()) < 0){
                if (current->getLeft() == nullptr){
                    Node<T>* new_node = new Node<T>(data);
                    current->setLeft(new_node);
                    new_node->setFather(current);
                    current->setHeight(current->getHeight()+1);
                }
                else {
                    insert(data, current->getLeft());
                    current->setHeight(max(current->getLeft(), current->getRight())+1);
                }
            }
            else {
                if (compare(data, current->getData()) > 0){
                    if (current->getRight() == nullptr){
                        Node<T>* new_node = new Node<T>(data);
                        current->setRight(new_node);
                        new_node->setFather(current);
                        current->setHeight(current->getHeight()+1);
                    }
                    else {
                        insert(data, current->getRight());
                        current->setHeight(max(current->getLeft(), current->getRight())+1);
                    }
                }
            }
        }
    }


    void printInOrder(Node<T> *node) {
        if (node != NULL) {
            if (node->getLeft() != NULL) {
                printInOrder(node->getLeft());
            }
            cout << node->getData() << " ";
            if (node->getRight() != NULL) {
                printInOrder(node->getRight());
            }
        }
    }
};




#endif //DSWET1_AVLTREE_H
