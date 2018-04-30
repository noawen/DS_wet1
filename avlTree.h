//
// Created by Dell on 30/04/2018.
//

#ifndef DSWET1_AVLTREE_H
#define DSWET1_AVLTREE_H

#include <iostream>
using std::cout;

template<class T, class Key>
class Node {
    T data;
    Key key;
    Node* father;
    Node* left, *right;

public:
    Node (const T& data, const Key& key){
        this->data = data;
        this->key = key;
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

    void setFather (const Node)<T, Key>* father){
        if (this == nullptr){
            return;
        }
        this->father = father;
    }

    void setRight (const Node)<T, Key>* right){
        if (this == nullptr){
            return;
        }
        this->father = right;
    }

    void setLeft (const Node)<T, Key>* left){
        if (this == nullptr){
            return;
        }
        this->left = left;
    }

    Key& getKey (){
        if (this == nullptr){
            return;
        }
        return this->key;
    }

    T& getData (){
        return this->data;
    }

    Node<T, Key>* getFather() {
        if (this == nullptr) {
            return nullptr;
        }
        return this->father;
    }

    Node<T, Key>* getRight() {
        if (this == nullptr) {
            return nullptr;
        }
        return this->right;
    }

    Node<T, Key>* getLeft() {
        if (this == nullptr) {
            return nullptr;
        }
        return this->left;
    }



};

template <class T, class Key, class compKey>
class AvlTree{
    Node<T, Key>* root;

public:
    AvlTree(){
        this->root = nullptr;
    }

    T& find (Key key, Node<T, Key>* current){
        if (current == nullptr){
            return nullptr;                         // maybe null is not good
        }
        else {
            compKey compare;
            if (compare(key, current->getKey()) == 0){
                return current->getData();
            }
            else {
                if (compare(key, current->getKey()) > 0){
                    find(key, current->getRight());
                }
                else {
                    find(key, current->getLeft());
                }
            }

        //RETURN NOT FOUND
        }
    }
};


#endif //DSWET1_AVLTREE_H
