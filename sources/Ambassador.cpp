#include "Ambassador.hpp"

using namespace std;

namespace coup{
    const size_t two = 2;

    void Ambassador::transfer(Player &player1, Player &player2){
        if(player1.coins() < 1){
            throw invalid_argument("Not enogh money");
        }
        player1.coinsNum--;
        player2.coinsNum++;
        this->lastAction="transfer";
        this->gamenum.nextTurn();
    }

    void Ambassador::block(Player &player){
         if(this->gamenum.blockable(player, "Captain") && this->gamenum.blockable(player, "Ambassador")){
            //this->stolen->coinsNum+=two;
            this->lastAction="block";
            player.coinsNum-=two;
        }
    }

    std::string Ambassador::role(){
        return "Ambassador";
    }
}