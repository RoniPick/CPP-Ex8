#include <string>
#include <iostream>
#include <vector>
#include "Game.hpp"

using namespace std;
#pragma once

namespace coup{
    class Player{
        friend class Game;
    protected:
        string name;
        Game &gamenum;
        

    public:
        string lastAction;
        size_t coinsNum=0;
        bool alive = true;
        Player(Game &num, string name);
        //~Player();

        void income();
        void foreign_aid();
        virtual void coup(Player &player);
        size_t coins();
        virtual string role();

    };
    
    
}