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
    AvlTree<Player,isBigger_byCoins_byID> *players_tree;

public:
    Clan();

    Clan(int id);

    Clan(int id, int coins);

    int getId();

    int getBestPlayerId();

    int getBestPlayerChallenges();

    int getNumOfPlayers();

    void setNumOfPlayers();

    void setNumOfPlayers(int num);

    void setBestPlayer(int id);

    void setBestPlayerChallenges(int challenges);

    void setPlayersTree (AvlTree <Player,isBigger_byCoins_byID>* tree);

    AvlTree <Player,isBigger_byCoins_byID>* getPalyersTree();

    Clan&operator=(const Clan& clan);

    bool operator== (Clan& clan);

    ~Clan() ;



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
