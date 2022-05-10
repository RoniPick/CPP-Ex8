#include <string>
#include <iostream>
#include "Player.hpp"

using namespace std;

namespace coup{
    class Captain:public Player{
    public:
        Player *stolen;
        Captain(Game &num, string name): Player(num, name){}
        
        void steal(Player &player);
        void block(Player &player);
        string role();
    };

}