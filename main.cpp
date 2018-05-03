#include <iostream>
#include "avlTree.h"
#include <cassert>
using std::endl;


/*
    std::cout << "Hello, World!" << std::endl;
    return 0;
}*/

class isBigger {
public:
    int operator()(int a, int b) {
        if (a < b) {
            return -1;
        }
        if (a > b) {
            return 1;
        }
        return 0;
    }
};

void test_insert_and_remove() {
    AvlTree<int, isBigger> avl = AvlTree<int, isBigger>();
    int array[] = {8, 5, 3, 9, 19};
    for (int i = 0; i < 5; i++) {
        avl.insert(array[i], avl.getRoot());
    }

    assert(avl.getRoot()->getHeight() == 2);

    if (avl.contain(30)){
        cout<<"OK";
        cout << endl;
    }

    if (!avl.contain(32)){
        cout<<"OK";
        cout << endl;
    }

    avl.printInOrder(avl.getRoot());
}


    /*
    sply.printInOrder(sply.getRoot());
    cout << endl;
    sply.find(18);
    sply.printInOrder(sply.getRoot());
    cout << endl;
    sply.remove(17);
*/
    // sply.printInOrder(sply.getRoot());
  //  cout << endl;
//}



int main() {
     test_insert_and_remove();
   // Addtrainer_test();
    //buyGladiator_test();
    return 0;
}