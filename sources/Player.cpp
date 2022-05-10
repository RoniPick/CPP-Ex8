#include "Player.hpp"
#include "Game.hpp"
#include <vector>

using namespace std;

namespace coup{
    const size_t two = 2;
    const size_t six = 6;
    const size_t seven = 7;
    const size_t ten = 10;

    Player::Player(Game &num, std::string& name) : gamenum(num){
        this->name = name;
        this->alive = true;
        this->lastAction = " ";
        if(this->gamenum.game_started){
            throw invalid_argument("Game allready started");
        }
        gamenum.addPlayer(*this);
    }

    void Player::income(){
        if(this->gamenum.players().size()<=1 && !this->gamenum.game_started){
            throw invalid_argument("Only 1 player");
        }
        this->gamenum.game_started = true;

        if(this->coins() >= ten){
            throw invalid_argument("Must coup");
        }

        if(this->gamenum.turn() != this->name){
            throw invalid_argument("Not your turn!:(");
        }

        this->coinsNum++;
        
        this->lastAction="income";
        this->gamenum.nextTurn();
     }

    void Player::foreign_aid(){
        if(this->gamenum.players().size()<=1 && !this->gamenum.game_started){
            throw invalid_argument("Only 1 player");
        }
        this->gamenum.game_started = true;

        if(this->coins() >= ten){
            throw invalid_argument("Must coup");
        }

        if(this->gamenum.turn() != this->name){
            throw invalid_argument("Not your turn!");
        }

        this->gamenum.addBlock("Duke", *this);
        this->gamenum.game_started = true;
        this->coinsNum+=two;
        this->lastAction="foreign_aid";
        this->gamenum.nextTurn();

    }

    void Player::coup(Player &player){
        if(this->coins() <= six){
            throw invalid_argument("Not enough coins");
        }
        if(!player.alive){
            throw invalid_argument("Player allready dead");
        }

        player.alive = false;
        this->coinsNum -= seven;
        this->lastAction="coup";
        this->gamenum.nextTurn();

    }

    string Player::role(){
        return "";
    }

    size_t Player::coins() const{
        return this->coinsNum;
    }
}