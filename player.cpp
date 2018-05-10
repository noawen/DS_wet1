//
// Created by Dell on 30/04/2018.
//

#include "player.h"

Player::Player(){
    this->id = 0;
    this->coins = 0;
}

Player::Player(int id, int coins){
    this->id = id;
    this->coins = coins;
    this->player_clan = NULL;
    this->num_of_challenges = 0;
}

int Player::getId() {
    if (!this)
        return 0;
    return this->id;
}

int Player::getCoins() {
    if (!this)
        return 0;
    return this->coins;
}

int Player::getChallenges() {
    if (!this)
        return 0;
    return this->num_of_challenges;
}

void Player::setCoins(int new_coins) {
    if (!this)
        return;
    this->coins = new_coins;
}

void Player::plusChallange() {
    if (!this)
        return;
    this->num_of_challenges = this->num_of_challenges+1;
}

void Player::setClan(Clan *clan) {
    if (!this)
        return;
    this->player_clan = clan;
}

Clan* Player::getClan() {
    if (!this)
        return NULL;
    return this->player_clan;
}

 std::ostream& operator << (std::ostream& os,  Player& player)
{
    os << "(" <<"id:"<<player.getId()<<" , " << "coins:"<<player.getCoins()<<")" << endl;
    return os ;
}

Player& Player::operator=(const Player& player){

    this->id = player.id;
    this->coins = player.coins;
    this->num_of_challenges = player.num_of_challenges;
    this->player_clan = player.player_clan;
    return *this;
}

bool Player::operator== (Player& player){
    return (this->id == player.id);
}


