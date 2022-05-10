#include <string>
#include <iostream>
#include <vector>
#include "Player.hpp"


using namespace std;

namespace coup{
    class Ambassador:public Player{

    public:
        Ambassador(Game num, string name): Player(num, name){}
        void block(Player &player);
        void transfer(Player &player1, Player &player2);
        string role();
    };

}