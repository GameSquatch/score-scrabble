//
//  Game.hpp
//  ScoreScrabble
//
//  Created by Ezekiel Williams on 7/7/17.
//  Copyright © 2017 Ezekiel Williams. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Player.hpp"

class Game {
private:
    std::vector<Player> players;
    unsigned short int nPlayers;
    
public:
    Game();
    
public:
    void GameLoop();
    
private:
    //start game
    void Intro();
    void EnterNPlayers();
    void InitializePlayers();
    void EnterNames();
    //play game
    void DisplayPlayers() const;
    
};

#endif /* Game_hpp */
