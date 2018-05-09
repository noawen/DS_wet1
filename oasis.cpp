//
// Created by Dell on 05/05/2018.
//

#include "oasis.h"
#include "malloc.h"


Oasis::Oasis(){

    this->best_player_challenges = 0;
    this->best_player_id = -1;
    this->tot_num_of_players = 0;
    AvlTree<Player,isBigger_byId_player>* players_id = new AvlTree<Player,isBigger_byId_player>();
    AvlTree<Player,isBigger_byCoins_byID>* players_coins = new AvlTree<Player,isBigger_byCoins_byID>();
    AvlTree<Clan,isBigger_byId_clan>* clans = new AvlTree<Clan,isBigger_byId_clan>();
    this->all_players_by_id = *players_id;
    this->all_players_by_coins = *players_coins;
    this->all_clans = *clans;
}

void Oasis::addPlayer(int playerID, int initialCoins) {
    Player to_find = Player(playerID,0);
    if (playerID <= 0 || initialCoins < 0) {
        throw INVALID_INPUT_OASIS();
    }
    // try {
    Player new_player = Player(playerID, initialCoins);
    //}
    // catch (std::bad_alloc&&){
    //     throw ALLOCATION_ERROR_OASIS();
    // }
    if (this->all_players_by_id.contain(new_player)) {
        throw FAILURE_OASIS();
    }
    this->all_players_by_id.insert(new_player);
    this->all_players_by_coins.insert(new_player);
    this->tot_num_of_players++;
    if (this->tot_num_of_players == 1) {
        this->best_player_id = playerID;
        this->best_player_challenges = 0;
    }
    int curr_chgs = this->all_players_by_id.find(to_find, this->all_players_by_id.getRoot()).getChallenges();

    if (this->best_player_challenges < curr_chgs) {
        this->best_player_challenges = curr_chgs;
        this->best_player_id = playerID;
    }
    if (this->best_player_challenges == curr_chgs) {
        if (playerID < this->best_player_id) {
            this->best_player_id = playerID;
            this->best_player_challenges = curr_chgs;
        }
    }
}


void Oasis::addClan( int clanID) {
    if (clanID <= 0) {
        throw INVALID_INPUT_OASIS();
    }
    Clan new_clan = Clan(clanID);
    if (this->all_clans.contain(new_clan)) {
        throw FAILURE_OASIS();
    }
    this->all_clans.insert(new_clan);
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
    if (found_player.getClan() != NULL){
        throw FAILURE_OASIS();
    }
    Clan found_clan = this->all_clans.find(clan_to_find,this->all_clans.getRoot());
    //found_player.setClan(&found_clan);
    this->all_players_by_id.find(player_to_find,this->all_players_by_id.getRoot()).setClan(&this->all_clans.find(clan_to_find,this->all_clans.getRoot()));
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
    this->all_clans.find(found_clan,this->all_clans.getRoot()).getPalyersTree()->insert(found_player);
    this->all_clans.find(found_clan,this->all_clans.getRoot()).setNumOfPlayers();
}

void Oasis::completeChallange(int playerID, int coins) {
    if ((coins <= 0) || (playerID <= 0)) {
        throw INVALID_INPUT_OASIS();
    }
    Player to_find = Player(playerID,0);
    int old_coins = this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot()).getCoins();
    int new_coins = old_coins + coins;
   // int relevant_clan = this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot()).getClan()->getId();

    this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot()).setCoins(new_coins);
    this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot()).plusChallange();

    int curr_num_chgs = this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot()).getChallenges();

    if (this->all_players_by_id.find(to_find, this->all_players_by_id.getRoot()).getChallenges() > best_player_challenges) {
        best_player_challenges = this->all_players_by_id.find(to_find, this->all_players_by_id.getRoot()).getChallenges();
        best_player_id = playerID;
    }
    if (this->all_players_by_id.find(to_find, this->all_players_by_id.getRoot()).getChallenges() == best_player_challenges){
        if (playerID < best_player_id){
            best_player_challenges = this->all_players_by_id.find(to_find, this->all_players_by_id.getRoot()).getChallenges();
            best_player_id = playerID;
        }
    }

    if (curr_num_chgs > this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot()).getClan()->getBestPlayerChallenges()){
        this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot()).getClan()->setBestPlayerChallenges(curr_num_chgs);
        this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot()).getClan()->setBestPlayer(playerID);
    }

    if (curr_num_chgs == this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot()).getClan()->getBestPlayerChallenges()) {
        if (playerID < this->all_players_by_id.find(to_find, this->all_players_by_id.getRoot()).getClan()->getBestPlayerId()) {
            this->all_players_by_id.find(to_find, this->all_players_by_id.getRoot()).getClan()->setBestPlayerChallenges(curr_num_chgs);
            this->all_players_by_id.find(to_find, this->all_players_by_id.getRoot()).getClan()->setBestPlayer(playerID);
        }
    }


    to_find.setCoins(old_coins);
    this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot()).getClan()->getPalyersTree()->remove(to_find);
    this->all_players_by_coins.remove(to_find);

    Player p1 = Player(312274814,1);
    this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot()).getClan()->getPalyersTree()->getRoot()->setData(p1);

    to_find.setCoins(new_coins);
    this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot()).getClan()->getPalyersTree()->insert(to_find);
    this->all_players_by_coins.insert(to_find);


}


void Oasis::getBestPlayer(int clanID, int *playerID) {
    if (clanID == 0 || playerID == NULL){
        throw INVALID_INPUT_OASIS();
    }
    if (clanID < 0) {
        if (this->tot_num_of_players != 0) {
            *playerID = this->best_player_id;
        }
        if (tot_num_of_players == 0) {
            *playerID = -1;
        }
        return;
    }
    Clan to_find = Clan (clanID);

    if (this->all_clans.find(clanID,this->all_clans.getRoot()).getNumOfPlayers() > 0){
        *playerID = this->all_clans.find(to_find,this->all_clans.getRoot()).getBestPlayerId();
    }
    if (this->all_clans.find(to_find,this->all_clans.getRoot()).getNumOfPlayers() == 0){
        *playerID = -1;
    }
}


void Oasis::getScoreboard(int clanID, int **players, int *numOfPlayers) {
    //bool trainerFound = false;
    if (clanID == 0 || players == NULL || numOfPlayers == NULL) {
        throw INVALID_INPUT_OASIS();
    }
    if (clanID < 0) {
        getScoreAux(&this->all_players_by_coins, players, numOfPlayers, this->tot_num_of_players);
    } else {
        Clan to_find = Clan(clanID);
        int num = this->all_clans.find(to_find, this->all_clans.getRoot()).getNumOfPlayers();
        getScoreAux((this->all_clans.find(to_find, this->all_clans.getRoot()).getPalyersTree()), players, numOfPlayers,
                    num);
        if (clanID > 0 && !this->all_clans.contain(to_find)) {
            throw FAILURE_OASIS();
        }
    }
}

void Oasis::uniteClans(int clanID1, int clanID2){
    if (clanID1 == clanID2 || clanID1 <= 0 || clanID2 <= 0 ){
        throw INVALID_INPUT_OASIS();
    }

    Clan clan1 = Clan(clanID1);
    Clan clan2 = Clan(clanID2);

    if (!this->all_clans.contain(clan1) || !(this->all_clans.contain(clan2))){
        throw FAILURE_OASIS();
    }

}


void Oasis:: getScoreAux(AvlTree<Player,isBigger_byCoins_byID> *tree, int **players, int *numOfPlayers, int size){
    *numOfPlayers = size;
    if(*numOfPlayers == 0){
        *players = NULL;
    } else {
        Player *players_tot = (Player*)malloc((*numOfPlayers) * sizeof(Player));
        tree->returnBackInOrder(tree->getRoot(),players_tot,0);
        int * player_temp = (int *) malloc((*numOfPlayers) * sizeof(int));
        for(int i = 0 ; i < *numOfPlayers ; i++){
            player_temp[i] = players_tot[i].getId();
        }
        *players = player_temp;
        free(players_tot);
    }
}


int Oasis::checkAccess (int id){
    Player to_find = Player (id , 0);
   // this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot());
   // Player found = this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot());
    int check = this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot()).getClan()->getNumOfPlayers();
    //Clan *found_clan = this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot()).getClan();
    //int check = found_clan->getNumOfPlayers();
   // int check = found.getClan()->getNumOfPlayers();
    return check;
}

Oasis::~Oasis() {

    //delete &this->trainers;
    //delete &this->all_glads_by_level;
    ////  this->all_glads_by_level = NULL;
    //  delete &this->all_glads_by_id;

}
