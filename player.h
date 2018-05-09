//
// Created by Dell on 30/04/2018.
//

#ifndef DSWET1_PLAYER_H
#define DSWET1_PLAYER_H


#include <iostream>
#include <ostream>
using std::cout;
using std::endl;

class Clan;
class isBigger;
class isBigger_byCoins_byID;
class isBigger_byId;

class Player {
    int id;
    int coins;
    int num_of_challenges;
    Clan *player_clan;

public:
    Player();

    Player(int id);

    Player(int id, int coins);

    int getId();

    int getCoins();

    int getChallenges();

    void setCoins(int coins);

    void plusChallange();

    void setClan (Clan *clan);

     Clan* getClan() ;

    Player&operator=(const Player& player);

    friend std::ostream& operator << (std::ostream& os,  Player& player);

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


class isBigger_byId_player {
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

class isBigger_byCoins_byID {
public:
    int operator()(Player &a, Player &b) {
        if (a.getCoins() < b.getCoins()) {
            return -1;
        }
        if (a.getCoins() > b.getCoins()) {
            return 1;
        }
        if (a.getCoins() == b.getCoins()) {
            if (a.getId() < b.getId()) {
                return 1;
            } else if((a.getId() > b.getId())) {
                return -1;
            }
        }
        return 0;
    }
};






#endif //DSWET1_PLAYER_H



