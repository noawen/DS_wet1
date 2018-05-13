//
// Created by Dell on 12/05/2018.
//
#include <iostream>
#include "player.h"
#include "avlTree.h"
#include "clan.h"

#define nullptr 0

#include "library1.h"

void test() {
    void *oasis = init();
    Clan clan(14);
    addClan(oasis, 14);
    quit(&oasis);

}
int main(){
    test();
}