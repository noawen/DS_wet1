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
    Node* father;
    Node* left, *right;

public:
    Node (const T& data){
        this->data = data;
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

    void setFather (const Node<T>* father){
        if (this == nullptr){
            return;
        }
        this->father = father;
    }

    void setRight (const Node<T>* right){
        if (this == nullptr){
            return;
        }
        this->right = right;
    }

    void setLeft (const Node<T>* left){
        if (this == nullptr){
            return;
        }
        this->left = left;
    }


    T& getData (){
        return this->data;
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

    T& find (T key, Node<T>* current){
        if (current == nullptr){
            return nullptr;                         // maybe null is not good
        }
        else {
            compKey compare;
            if (compare(key, current->getData()) == 0){
                return current->getData();
            }
            else {
                if (compare(key, current->getData()) > 0){
                   return find(key, current->getRight());
                }
                else {
                    return find(key, current->getLeft());
                }
            }

        //RETURN NOT FOUND
        }
    }
};


#endif //DSWET1_AVLTREE_H
