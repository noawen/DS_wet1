//
// Created by Dell on 30/04/2018.
//

#ifndef DSWET1_AVLTREE_H
#define DSWET1_AVLTREE_H

#include <iostream>
using std::cout;

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
class AvlTree{
    Node<T>* root;

public:
    AvlTree(){
        this->root = nullptr;
    }

    T& find (T data, Node<T>* current){
        if (current == nullptr){
            return nullptr;                         // maybe null is not good
        }
        else {
            compKey compare;
            if (compare(data, current->getData()) == 0){
                return current->getData();
            }
            else {
                if (compare(data, current->getData()) > 0){
                   return find(data, current->getRight());
                }
                else {
                    return find(data, current->getLeft());
                }
            }

        //RETURN NOT FOUND
        }
    }

    Node<T>* insert (T data, Node<T>* current){
        //what about failure
        compKey compare;
        if (current == nullptr){
            Node<T>* new_node = new Node<T>(data);
            current = new_node;
        }
        else {
            if (compKey(data, current->getData()) < 0){
                current->setLeft(insert(data, current->getLeft()));
            }
            else {
                if (compKey(data, current->getData()) > 0){
                    current->setRight(insert(data, current->getRight()));
                }
            }
        }
    }
};


#endif //DSWET1_AVLTREE_H
