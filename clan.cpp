//
// Created by Dell on 30/04/2018.
//

#include "clan.h"

Clan::Clan() {
    this->id = 0;
    this->best_player_id = 0;
    this->best_player_challenges = -1;
    this->num_of_players = 0;
    this->players_tree = new AvlTree<Player, isBigger_byCoins_byID>();
}
Clan::Clan(int id){
    this->id = id;
    this->best_player_id = 0;
    this->best_player_challenges = -1;
    this->num_of_players = 0;
    this->players_tree = new AvlTree<Player, isBigger_byCoins_byID>();
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

void Clan::setNumOfPlayers() {
    if (!this)
        return;
    this->num_of_players ++;
}

void Clan::setNumOfPlayers(int num){
    if (!this)
        return;
    this->num_of_players = num;
}

int Clan::getNumOfPlayers() {
    if (!this){
        return 0;
    }
    return this->num_of_players;
}

AvlTree<Player,isBigger_byCoins_byID>* Clan ::getPalyersTree(){
    if (!this)
        return NULL;
    return this->players_tree;
}


void Clan::setPlayersTree(AvlTree<Player, isBigger_byCoins_byID> *tree) {
    if (!this)
        return;
    this->players_tree = tree;
}


Clan& Clan::operator=(const Clan& clan){

    this->id = clan.id;
    this->best_player_id = clan.best_player_id;
    this->best_player_challenges = clan.best_player_challenges;
    this->num_of_players = clan.num_of_players;
    this->players_tree = clan.players_tree;
    return *this;
}

bool Clan::operator== (Clan& clan){
    return (this->id == clan.id);
}

Clan::~Clan() {
    this->players_tree = nullptr;
//this->setBestPlayerChallenges(0);
//this->setNumOfPlayers(0);
}