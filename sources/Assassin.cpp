#include "Assassin.hpp"

using namespace std;

namespace coup{
    const size_t three = 3;
    const size_t six = 6;
    const size_t seven = 7;

    void Assassin::coup(Player &player){
        if(this->coinsNum<three){
            throw invalid_argument("Not enough coins");
        }

        else if(this->coinsNum>=three && this->coinsNum<=six){
            this->coinsNum-=three;
            player.alive = false;
            this->gamenum.addBlock("Contessa", *this);
            this->lastAction="coupBy3";
            last_killed = &player;
            this->gamenum.nextTurn();
        }

        else{
            this->coinsNum-=seven;
            player.alive = false;
            this->lastAction="coup";
            this->gamenum.nextTurn();
        }
    }

    std::string Assassin::role(){
        return "Assassin";
    }

    Player &Assassin::get_lastkilled(){
        return *last_killed;
    }
}
