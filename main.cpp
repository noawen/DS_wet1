#include <iostream>
#include "avlTree.h"
#include "clan.h"
#include "player.h"
#include "oasis.h"
#include <cassert>
using std::endl;



void test_insert() {
/*
    AvlTree<int, isBigger> int_avl = AvlTree<int, isBigger>();
    int array[] = {8,7,6};
    for (int i = 0; i < 3; i++) {
        int_avl.insert(array[i], int_avl.getRoot());
    }

    int_avl.printInOrder(int_avl.getRoot());
    cout<<endl;
    int_avl.remove(7,int_avl.getRoot());
    int_avl.printInOrder(int_avl.getRoot());
    //AvlTree<Player, isBigger_byId> player_avl_id = AvlTree<Player, isBigger_byId>();
    */

    AvlTree<Player, isBigger_byCoins_byId> player_avl_coins = AvlTree<Player, isBigger_byCoins_byId>();
    Player p1 = Player(31,50);
    Player p2 = Player(3122,100);
    Player p3 = Player(31227,55);
    Player p4 = Player(3122748,55);
    Player p5 = Player(31227481,2);
    Player p6 = Player(312274,55);

    player_avl_coins.insert(p1,player_avl_coins.getRoot());

    player_avl_coins.insert(p2,player_avl_coins.getRoot());
    player_avl_coins.insert(p3,player_avl_coins.getRoot());
    player_avl_coins.insert(p4,player_avl_coins.getRoot());
    player_avl_coins.insert(p5,player_avl_coins.getRoot());
    player_avl_coins.insert(p6,player_avl_coins.getRoot());


   // if(player_avl_coins.contain(p3)){
      //  cout<<"OK"<<endl;
    //}


    player_avl_coins.printBackInOrder(player_avl_coins.getRoot());
    cout<<endl;
    player_avl_coins.remove(p3,player_avl_coins.getRoot());
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
/*
void test_oasis() {
    Oasis oasis = Oasis();
    oasis.addPlayer(312,10);
    oasis.addPlayer(3122,5);
    oasis.addPlayer(3123,5);
    oasis.addClan(207);
    oasis.joinClan(3123,207);
    oasis.joinClan(3122,207);
}
 */
int main() {
     test_insert();
   // test_oasis();

    return 0;
}