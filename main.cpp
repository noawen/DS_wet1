#include <iostream>
#include "avlTree.h"
#include "clan.h"
#include "player.h"
#include <cassert>
using std::endl;



void test_insert_and_remove() {
    /*
    AvlTree<int, isBigger> int_avl = AvlTree<int, isBigger>();
    int array[] = {8, 5, 3, 9, 19};
    for (int i = 0; i < 5; i++) {
        int_avl.insert(array[i], int_avl.getRoot());
*/

    //AvlTree<Player, isBigger_byId> player_avl_id = AvlTree<Player, isBigger_byId>();
    AvlTree<Player, isBigger_byCoins_byId> player_avl_coins = AvlTree<Player, isBigger_byCoins_byId>();

    Player p1 = Player(1,50);
    Player p2 = Player(2,100);
    Player p3 = Player(3,55);
    Player p4 = Player(4,700);

    player_avl_coins.insert(p1,player_avl_coins.getRoot());
    player_avl_coins.insert(p2,player_avl_coins.getRoot());
    player_avl_coins.insert(p3,player_avl_coins.getRoot());
    player_avl_coins.insert(p4,player_avl_coins.getRoot());

    player_avl_coins.printBackInOrder(player_avl_coins.getRoot());
    //player_avl_id.insert(p1,player_avl_id.getRoot());
  //  player_avl_id.insert(p2,player_avl_id.getRoot());
  //  player_avl_id.insert(p3,player_avl_id.getRoot());
    }

/*
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

*/

int main() {
     test_insert_and_remove();
   // Addtrainer_test();
    //buyGladiator_test();
    return 0;
}