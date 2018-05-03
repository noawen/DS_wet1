//
// Created by Dell on 30/04/2018.
//

#ifndef DSWET1_PLAYER_H
#define DSWET1_PLAYER_H


#include "iostream"

class Clan;
class isBigger;
class isBigger_byCoins;
class isBigger_byId;

class Player {
    int id;
    int coins;
   // int num_of_challenges;
    Clan *player_clan;

public:
    Player();

    Player(int id);

    Player(int id, int coins);

    int getId();

    int getCoins();

  //  int get_num_of_challenges();

};



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


class isBigger_byId {
public:
    int operator()(Player& a, Player& b) {
        if (a.getId() < b.getId()) {
            return -1;
        }
        if (a.getId() > b.getId()) {
            return 1;
        }
        return 0;
    }
};

class isBigger_byCoins {
public:
    int operator()(Player& a, Player& b) {
        if (a.getCoins() < b.getCoins()) {
            return -1;
        }
        if (a.getCoins() > b.getCoins()) {
            return 1;
        }
        return 0;
    }
};



/*
public:
    Gladiator();

    Gladiator(int id);

    Gladiator(int level, int id);

    Gladiator(const Gladiator& glad);

    Gladiator(int level,int id,  Trainer* glad_trainer);

    Gladiator&operator=(const Gladiator& glad);

    int operator- (Gladiator& glad) const;

    bool operator== (Gladiator& glad);

    bool operator!= (Gladiator& glad);

    void setLevel(int level);

    void setId(int id);

    void setTrainer(Trainer* trainer);

    int getId();

    int getLevel();

    Trainer* getTrainer();

};
*/
#endif //DSWET1_PLAYER_H



