//
// Created by Dell on 30/04/2018.
//

#include "player.h"

Player::Player(){
    this->id = 0;
    this->coins = 0;

}
//Trainer::Trainer() : id(0) {};

Player::Player(int id, int coins){
    this->id = id;
    this->coins = coins;
    this->player_clan = NULL;

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
