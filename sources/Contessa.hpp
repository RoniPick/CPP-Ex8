#include <string>
#include <iostream>
#include "Player.hpp"

using namespace std;

namespace coup{
    class Contessa:public Player{

    public:
        Contessa(Game &num, string name): Player(num, name){}
        
        void block(Player &player);

        string role();
    };

}