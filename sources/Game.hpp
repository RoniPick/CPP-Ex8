#include <string>
#include <iostream>
#include <vector>

#pragma once

namespace coup{
    class Player;
}

using namespace std;

namespace coup{
    class Game{
    private:
    std::vector<coup::Player*> playersList;
    size_t curplayer;

    std::vector<coup::Player*> dukeBlock;
    std::vector<coup::Player*> ambassadorBlock;
    std::vector<coup::Player*> captainBlock;
    std::vector<coup::Player*> contessaBlock;

    public:
        bool game_started;
        Game();

        string turn();
        vector<string> players();
        string winner();
        void addPlayer(Player &player);
        void nextTurn();
        void addBlock(string n, Player &player);
        void removeBlock();
        bool blockable(Player &player, string role);
    };



}