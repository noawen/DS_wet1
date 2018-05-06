//
// Created by Dell on 05/05/2018.
//

#include "oasis.h"


Oasis::Oasis(){

    this->best_player_challenges = 0;
    this->best_player_id = -1;
    AvlTree<Player,isBigger_byId_player>* players_id = new AvlTree<Player,isBigger_byId_player>();
    AvlTree<Player,isBigger_byCoins>* players_coins = new AvlTree<Player,isBigger_byCoins>();
    AvlTree<Clan,isBigger_byId_clan>* clans = new AvlTree<Clan,isBigger_byId_clan>();
    this->all_players_by_id = *players_id;
    this->all_players_by_coins = *players_coins;
    this->all_clans = *clans;
}

void Oasis::addPlayer(int playerID, int initialCoins) {
    if (playerID <= 0 || initialCoins < 0){
        throw INVALID_INPUT_OASIS();
    }
   // try {
        Player new_player = Player(playerID, initialCoins);
    //}
   // catch (std::bad_alloc&&){
   //     throw ALLOCATION_ERROR_OASIS();
   // }
    if (this->all_players_by_id.contain(new_player)){
        throw FAILURE_OASIS();
    }
    this->all_players_by_id.insert(new_player,all_players_by_id.getRoot());
    this->all_players_by_coins.insert(new_player,all_players_by_coins.getRoot());
}

void Oasis::addClan( int clanID) {
    if (clanID <= 0) {
        throw INVALID_INPUT_OASIS();
    }
    Clan new_clan = Clan(clanID);
    if (this->all_clans.contain(new_clan)) {
        throw FAILURE_OASIS();
    }
    this->all_clans.insert(new_clan,this->all_clans.getRoot());
}

void Oasis::joinClan(int playerID, int clanID) {
    if ((clanID <= 0) || (playerID <= 0)) {
        throw INVALID_INPUT_OASIS();
    }

    Player player_to_find = Player(playerID,0);
    Clan clan_to_find = Clan(clanID);

    if ((!this->all_players_by_id.contain(player_to_find)) || !this->all_clans.contain(clan_to_find)){
        throw FAILURE_OASIS();
    }
    Player found_player = this->all_players_by_id.find(player_to_find,this->all_players_by_id.getRoot());
    if (player_to_find.getClan() != NULL){
        throw FAILURE_OASIS();
    }
    Clan found_clan = this->all_clans.find(clan_to_find,this->all_clans.getRoot());
    //found_player.setClan(&found_clan);
    this->all_players_by_id.find(player_to_find,this->all_players_by_id.getRoot()).setClan(&found_clan);
    //updete best player details

    if (found_player.getChallenges() > found_clan.getBestPlayerChallenges() ){
        this->all_clans.find(found_clan,this->all_clans.getRoot()).setBestPlayerChallenges(found_player.getChallenges());
        this->all_clans.find(found_clan,this->all_clans.getRoot()).setBestPlayer(found_player.getId());
    }

    if (found_player.getChallenges() == found_clan.getBestPlayerChallenges() ) {
        if (found_player.getId() < found_clan.getBestPlayerId()) {
            this->all_clans.find(found_clan, this->all_clans.getRoot()).setBestPlayerChallenges(
                    found_player.getChallenges());
            this->all_clans.find(found_clan, this->all_clans.getRoot()).setBestPlayer(found_player.getId());
        }
    }
    this->all_clans.find(found_clan,this->all_clans.getRoot()).getPalyersTree()->insert(found_player,this->all_clans.find(found_clan,this->all_clans.getRoot()).getPalyersTree()->getRoot());
    this->all_clans.find(found_clan,this->all_clans.getRoot()).setNumOfPlayers();
}
