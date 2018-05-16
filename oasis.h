//
// Created by Dell on 05/05/2018.
//

#ifndef DSWET1_OASIS_H
#define DSWET1_OASIS_H

//#include "player.h"
#include "clan.h"
#include "avlTree.h"
#include "iostream"

class OasisExceptions{};
class FAILURE_OASIS:             public OasisExceptions{};
class ALLOCATION_ERROR_OASIS:    public OasisExceptions{};
class INVALID_INPUT_OASIS:       public OasisExceptions{};

class Oasis {
    int best_player_id;
    int best_player_challenges;
    int tot_num_of_players;
    AvlTree<Player, isBigger_byId_player> all_players_by_id;
    AvlTree<Player, isBigger_byCoins_byID> all_players_by_coins;
    AvlTree<Clan, isBigger_byId_clan> all_clans;

public:

    Oasis();

    void addPlayer(int playerID, int initialCoins);

    void addClan(int clanID);

    void joinClan(int playerID, int clanID);

    void getBestPlayer(int clanID, int *playerID);

    void completeChallange(int playerID, int coins);

    void getScoreboard(int clanID, int **players, int *numOfPlayers);

    void getScoreAux (AvlTree<Player,isBigger_byCoins_byID>*, int **players, int *numOfPlayers, int size);

    void uniteClans(int clanID1, int clanID2);

    void makeTwoArrays (int id1, int id2, int maxID);

    void mergePlayers(Player **a, int na, Player **b, int nb, Player **c);

    void quit();

    ~Oasis();

};

#endif //DSWET1_OASIS_H
