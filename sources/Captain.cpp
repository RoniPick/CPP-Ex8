#include "Captain.hpp"

namespace coup{
    const size_t two = 2;

    void Captain::steal(Player &player){
        this->stolen = &player;
        if(player.coinsNum < 1){
           throw invalid_argument("Not enogh money!");
        }
        
        if(player.coinsNum>=two){
           player.coinsNum-=two; 
           this->coinsNum+=two;
           this->lastAction="steal";
        }

        else{
            player.coinsNum=0;
            this->coinsNum+=1;
            this->lastAction="steal";

        }

        this->gamenum.addBlock("Captain", *this);
        this->gamenum.addBlock("Ambassador", *this);

     }

    void Captain::block(Player &player){
        if(this->gamenum.blockable(player, "Captain") && this->gamenum.blockable(player, "Ambassador")){
            this->stolen->coinsNum+=two;
            player.coinsNum-=two;
            this->lastAction="block";
        }

    }

    std::string Captain::role(){
        return "Captain";
    }
}