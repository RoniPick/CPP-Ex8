#include "Contessa.hpp"
#include "Assassin.hpp"
using namespace coup;
using namespace std;

namespace coup{
    void Contessa::block(Player &player){
        if(this->alive == false){
            throw invalid_argument("Player dead");
        }

        if(player.role() != "Assassin"){
            throw invalid_argument("Player cant kill");
        }

        if(player.lastAction != "coupBy3" && player.role() == "Assassin"){
            throw invalid_argument("Cant realive");
        }
        Assassin *assas = dynamic_cast<Assassin *>(&player);
        assas->get_lastkilled().alive = true;
    }

    std::string Contessa::role(){
        return "Contessa";
    }
}