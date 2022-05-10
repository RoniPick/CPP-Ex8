#include "Game.hpp"
#include <iostream>
#include <vector>
#include "Player.hpp"

namespace coup{
    const size_t one = 1;
    const size_t six = 6;

    Game::Game(){
        std::vector<coup::Player*> playersList;
        this->curplayer = 0;
        this->game_started = false;
    }
    
    string Game::turn(){
        return this->playersList.at(this->curplayer)->name;
    }

    vector<string> Game::players(){
        vector<string> ans;
        size_t active =0;
        for(Player *p : this->playersList){
            if(p->alive == true){
                ans.push_back(p->name);
                active++;
            }
        }

        if(active < 1 || active > 7){
            throw invalid_argument("wrong number of players");
        }

        return ans;
    }

    string Game::winner(){
        if(playersList.size() <= one){
            throw invalid_argument("Can't play game with 1 player");
        }

        size_t active = 0;
        Player *win;
        for(Player *p : playersList){
            if(p->alive == true){
                active++;
                win = p;
            }
        }
        if(active > 1){
            throw invalid_argument("Too many participents still in the game!"); 
        }

        return win->name;
    }

    void Game::addPlayer(Player &player){
        if(playersList.size() >= 6){
            throw invalid_argument("The list of players if full");
        }
        else{
            this->playersList.push_back(&player);
        }
    }

    void Game::nextTurn(){
        size_t mod = this->playersList.size();
        this->curplayer = (this->curplayer+1) % mod;

        bool next = false;
        while(next == false){
           if(this->playersList.at(this->curplayer)->alive == false){
                this->curplayer = (this->curplayer+1) % mod;
            } 
            else{
                //this->curplayer = this->curplayer % mod;
                next = true;
            }
        }

        removeBlock();
    }

//add the player into the list of the role that can block him
    void Game::addBlock(string n, Player &player){
        if(n == "Duke"){
            dukeBlock.push_back(&player);
        }

        else if(n == "Ambassador"){
            ambassadorBlock.push_back(&player);
        }

        else if(n == "Captain"){
            captainBlock.push_back(&player);
        }

        else if(n == "Contessa"){
            contessaBlock.push_back(&player);
        }
    }

//removing the player from the blocking list before the next turn
    void Game::removeBlock(){
        Player *cur = playersList.at(curplayer);
        long i=0;

        for(Player *p : contessaBlock){
            if(p->name == cur->name){
                contessaBlock.erase(contessaBlock.begin()+i);
            }
            i++;
        }

        i=0;
        for(Player *p : dukeBlock){
            if(p->name == cur->name){
                dukeBlock.erase(dukeBlock.begin()+i);
            }
            i++;
        }

        i=0;
        for(Player *p : ambassadorBlock){
            if(p->name == cur->name){
                ambassadorBlock.erase(ambassadorBlock.begin()+i);
            }
            i++;
        }

        i=0;
        for(Player *p : captainBlock){
            if(p->name == cur->name){
                captainBlock.erase(captainBlock.begin()+i);
            }
            i++;
        }
    }

//check if i can block the player and if the player in the list
    bool Game::blockable(Player &player, string role){
        long i=0;
        if(role == "Duke"){
            for(Player *p : dukeBlock){
                if(p->name == player.name){
                    dukeBlock.erase(dukeBlock.begin()+i);
                    return true;
                }
                i++;
            }
        }

        else if(role == "Contessa"){
            for(Player *p : contessaBlock){
                if(p->name == player.name){
                    contessaBlock.erase(contessaBlock.begin()+i);
                    return true;
                }
                i++;
            }
        }

        else if(role == "Ambassador"){
            for(Player *p : ambassadorBlock){
                if(p->name == player.name){
                    ambassadorBlock.erase(ambassadorBlock.begin() +i);
                    return true;
                }
                i++;
            }
        }
        
        else if(role == "Captain"){
            for(Player *p : captainBlock){
                if(p->name == player.name){
                    captainBlock.erase(captainBlock.begin()+i);
                }
                i++;
            }
        }

        return false;
    }

}