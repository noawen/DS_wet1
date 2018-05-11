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
    Player to_find = Player (playerID,0);
   // Clan clan_to_find = Clan();
    if(!this->all_players_by_id.contain(to_find)){
        throw FAILURE_OASIS();
    }

    //update player's trees
    to_find = this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot());
    this->all_players_by_coins.remove(to_find);
    if (to_find.getClan() != NULL) {
        to_find.getClan()->getPalyersTree()->remove(to_find);
    }
    to_find.setCoins(to_find.getCoins()+coins);
    to_find.plusChallange();
    this->all_players_by_coins.insert(to_find);
    this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot()).setCoins(to_find.getCoins());
    this->all_players_by_id.find(to_find,this->all_players_by_id.getRoot()).plusChallange();

    if (best_player_challenges <= to_find.getChallenges()){
        if (best_player_challenges < to_find.getChallenges()){
            best_player_challenges = to_find.getChallenges();
            best_player_id = playerID;
        }
        else{
            if (playerID < best_player_id){
                best_player_challenges = to_find.getChallenges();
                best_player_id = playerID;
            }
        }
    }
    if (to_find.getClan() != NULL) {
       if( to_find.getClan()->getBestPlayerChallenges() <= to_find.getChallenges()){
           if (to_find.getClan()->getBestPlayerChallenges() < to_find.getChallenges()) {
               to_find.getClan()->setBestPlayerChallenges(to_find.getChallenges());
               to_find.getClan()->setBestPlayer(playerID);
           }
           else {
               if (to_find.getClan()->getBestPlayerId() > playerID  ){
                   to_find.getClan()->setBestPlayer(playerID);
                   to_find.getClan()->setBestPlayerChallenges(to_find.getChallenges());
               }
           }
       }


    to_find.getClan()->getPalyersTree()->insert(to_find);

}

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
    if(!this->all_clans.contain(to_find)){
        throw FAILURE_OASIS();
    }
    if (this->all_clans.find(clanID,this->all_clans.getRoot()).getNumOfPlayers() > 0){
        *playerID = this->all_clans.find(to_find,this->all_clans.getRoot()).getBestPlayerId();
    }
    if (this->all_clans.find(to_find,this->all_clans.getRoot()).getNumOfPlayers() == 0){
        *playerID = -1;
    }
}


void Oasis::getScoreboard(int clanID, int **players, int *numOfPlayers) {
    //bool trainerFound = false;
    Clan to_find = Clan(clanID);
    if (clanID == 0 || players == NULL || numOfPlayers == NULL) {
        throw INVALID_INPUT_OASIS();
    }
    if (clanID > 0 && !this->all_clans.contain(to_find)) {
        throw FAILURE_OASIS();
    }
    if (clanID < 0) {
        getScoreAux(&this->all_players_by_coins, players, numOfPlayers, this->tot_num_of_players);
    } else {

        int num = this->all_clans.find(to_find, this->all_clans.getRoot()).getNumOfPlayers();
        getScoreAux((this->all_clans.find(to_find, this->all_clans.getRoot()).getPalyersTree()), players, numOfPlayers,
                    num);

    }
}

static int max (int a, int b){
    return a > b ? a : b;
}

void Oasis::uniteClans(int clanID1, int clanID2){
    if (clanID1 == clanID2 || clanID1 <= 0 || clanID2 <= 0 ){
        throw INVALID_INPUT_OASIS();
    }
    // maybe cases of allocation error should be added
    Clan clan1 = Clan(clanID1);
    Clan clan2 = Clan(clanID2);

    if (!this->all_clans.contain(clan1) || !(this->all_clans.contain(clan2))){
        throw FAILURE_OASIS();
    }
    clan1 = this->all_clans.find(clanID1, this->all_clans.getRoot());  //finding the requested clans
    clan2 = this->all_clans.find(clanID2, this->all_clans.getRoot());
    Player arr1 [clan1.getNumOfPlayers()];                                  //two arrays for players
    Player arr2 [clan2.getNumOfPlayers()];
    this->all_players_by_id.printTreeToArray(clan1.getPalyersTree()->getRoot(), arr1 + sizeof(int)* clan1.getNumOfPlayers(), 0);//put the players into array
    this->all_players_by_id.printTreeToArray(clan2.getPalyersTree()->getRoot(), arr2 + sizeof(int)* clan2.getNumOfPlayers(), 0);
    Player merged_arr [clan1.getNumOfPlayers() + clan2.getNumOfPlayers()];                                      // merged array of two clans players
    this->mergePlayers(arr1,clan1.getNumOfPlayers(),arr2, clan2.getNumOfPlayers(),merged_arr);
    AvlTree<Player,isBigger_byCoins_byID>* mergedClan = new AvlTree<Player, isBigger_byCoins_byID>();                          // the new tree with the two clans players

    for (int i = 0; i < clan1.getNumOfPlayers() + clan2.getNumOfPlayers(); i++){
        if (merged_arr[i].getChallenges() == 0){
            i++;
        } else{
            mergedClan->insert(merged_arr[i]);
        }
    }
    this->all_clans.find(clanID1, this->all_clans.getRoot()).getPalyersTree()->destroyTree
            (this->all_clans.find(clanID1, this->all_clans.getRoot()).getPalyersTree()->getRoot()); //destroying first tree
    this->all_clans.find(clanID2, this->all_clans.getRoot()).getPalyersTree()->destroyTree
            (this->all_clans.find(clanID2, this->all_clans.getRoot()).getPalyersTree()->getRoot()); //destroying second tree
    this->all_clans.remove(clan1); //remove first clan from the clans tree
    this->all_clans.remove(clan2); //remove second clan from the clans tree
    int newClanId = clan1.getNumOfPlayers() > clan2.getNumOfPlayers() ? clan1.getId() : clan2.getId(); //finding the requested id
    if (clan1.getNumOfPlayers() == clan2.getNumOfPlayers()){
        newClanId = clan1.getId() < clan2.getId() ? clan1.getId() : clan2.getId();
    }
    Clan newClan(newClanId);                        //making new clan and put it the clan tree
    newClan.setBestPlayer(max(clan1.getBestPlayerId(), clan2.getBestPlayerId()));
    newClan.setBestPlayerChallenges(max(clan1.getBestPlayerChallenges(), clan2.getBestPlayerChallenges()));
    newClan.setNumOfPlayers(clan1.getNumOfPlayers() + clan2.getNumOfPlayers());
    newClan.setPlayersTree(mergedClan);
    this->all_clans.insert(newClan);
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

void Oasis::mergePlayers(Player *a, int na, Player *b, int nb, Player *c){
    int ia, ib , ic;
    for (ia = ib = ic = 0; (ia < na)&&(ib < nb) ;ic++) {

        if (a[ia].getCoins() < b[ib].getCoins()){
            c[ic] = a[ia];
            ia++;
        }
        else{
            c[ic] = b[ib];
            ib++;
        }
    }
    for (; ia < na; ia++, ic++)
        c[ic] = a[ia];
    for (; ib < nb; ib++, ic++)
        c[ic] = b[ib];
}

void Oasis::quit(){
    //this->all_players_by_coins.destroyTree(this->all_players_by_coins.getRoot());
   // this->all_players_by_id.destroyTree(this->all_players_by_id.getRoot());
  //  delete &this->all_players_by_coins;
   // delete &this->all_players_by_id;
    return;
}


Oasis::~Oasis() {
    delete &this->all_clans;
    delete &this->all_players_by_id;
    delete &this->all_players_by_coins;
}
