//
// Created by Dell on 30/04/2018.
//

#include "clan.h"

Clan::Clan(int id){
    this->id = id;
    this->best_player_challenges = 0;
    this->best_player_challenges = 0;
    this->num_of_players = 0;
    this->players_tree = new AvlTree<Player, isBigger_byCoins_byId>();
}

int Clan::getId() {
    if (!this)
        return 0;
    return this->id;
}

int Clan::getBestPlayerId(){
    if (!this){
        return 0;
    }
    return this->best_player_id;
}

int Clan::getBestPlayerChallenges(){
    if (!this){
        return 0;
    }
    return this->best_player_challenges;
}

void Clan::setBestPlayer(int id){
    if (!this)
        return;
    this->best_player_id = id;
}

void Clan::setBestPlayerChallenges(int challenges){
    if (!this)
        return;
    this->best_player_challenges = challenges;
}

AvlTree<Player,isBigger_byCoins_byId>*Clan ::getPalyersTree(){
        if (!this)
            return NULL;
        return this->players_tree;
    }
