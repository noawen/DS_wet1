//
// Created by Dell on 05/05/2018.
//

#include "library1.h"
#include "oasis.h"


void* init(){
    Oasis *DS;
    try {
        DS = new Oasis();
    }
    catch (std::bad_alloc&){
        return NULL;
    }
    return (void*)DS;
}

StatusType addPlayer(void *DS, int playerID, int initialCoins){
    try{
        ((Oasis*)DS)->addPlayer(playerID,initialCoins);
    }
    catch(INVALID_INPUT_OASIS&){
        return INVALID_INPUT;
    }
    catch (FAILURE_OASIS&){
        return FAILURE;
    }
    catch (std::bad_alloc&){
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType addClan(void *DS, int clanID){
    try{
        ((Oasis*)DS)->addClan(clanID);
    }
    catch(INVALID_INPUT_OASIS&){
        return INVALID_INPUT;
    }
    catch (FAILURE_OASIS&){
        return FAILURE;
    }
    catch (std::bad_alloc&){
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}


StatusType joinClan(void *DS, int playerID, int clanID){
    try{
        ((Oasis*)DS)->joinClan(playerID,clanID);
    }
    catch(INVALID_INPUT_OASIS&){
        return INVALID_INPUT;
    }
    catch (FAILURE_OASIS&){
        return FAILURE;
    }

    catch (std::bad_alloc&){
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType completeChallange(void *DS, int playerID, int coins){
    try{
        ((Oasis*)DS)->completeChallange(playerID,coins);
    }
    catch(INVALID_INPUT_OASIS&){
        return INVALID_INPUT;
    }
    catch (FAILURE_OASIS&){
        return FAILURE;
    }

    catch (std::bad_alloc&){
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

StatusType getBestPlayer(void *DS, int clanID, int* playerID){
    try{
        ((Oasis*)DS)->getBestPlayer(clanID,playerID);
    }
    catch(INVALID_INPUT_OASIS&){
        return INVALID_INPUT;
    }
    catch (FAILURE_OASIS&){
        return FAILURE;
    }


    return SUCCESS;
}

StatusType getScoreboard(void *DS, int clanID, int** players, int* numOfPlayers){
    try{
        ((Oasis*)DS)->getScoreboard(clanID,players,numOfPlayers);
    }
    catch(INVALID_INPUT_OASIS&){
        return INVALID_INPUT;
    }
    catch (FAILURE_OASIS&){
        return FAILURE;
    }
    catch (std::bad_alloc&){
        return ALLOCATION_ERROR;
    }

    return SUCCESS;
}