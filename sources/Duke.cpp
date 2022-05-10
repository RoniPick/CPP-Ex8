#include "Duke.hpp"

using namespace std;

namespace coup{
    
    void Duke::block(Player &player){
        if(this->gamenum.blockable(player, "Duke")){
            if(player.coinsNum>=2){
                player.coinsNum-=2; 
                this->lastAction="block";
            }

            else{
                player.coinsNum=0;
                this->lastAction="block";
            }
        }

        else{
            throw invalid_argument("Can't block player");
        }
    }

    void Duke::tax(){
        this->coinsNum+=3;
        this->lastAction="tax";
        this->gamenum.nextTurn();
    }

    std::string Duke::role(){
        return "Duke";
    }
}