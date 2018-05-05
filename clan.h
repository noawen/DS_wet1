//
// Created by Dell on 30/04/2018.
//

#ifndef DSWET1_CLAN_H
#define DSWET1_CLAN_H

#include "player.h"
#include "avlTree.h"
#include "iostream"

class isBigger_byId_clan;
class Player;

class Clan {
    int id;
    int best_player_id, best_player_challenges;
    int num_of_players;
    AvlTree<Player,isBigger_byCoins_byId> *players_tree;

public:
    Clan();

    Clan(int id);

    Clan(int id, int coins);

    int getId();

    int getBestPlayerId();

    int getBestPlayerChallenges();

    void setBestPlayer(int id);

    void setBestPlayerChallenges(int challenges);

    AvlTree<Player,isBigger_byCoins_byId>* getPalyersTree();

};


class isBigger_byId_clan {
public:
    int operator()(Clan& a, Clan& b) {
        if (a.getId() < b.getId()) {
            return -1;
        }
        if (a.getId() > b.getId()) {
            return 1;
        }
        return 0;
    }
};


#endif //DSWET1_CLAN_H
