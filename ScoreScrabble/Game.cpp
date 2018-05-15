//
//  Game.cpp
//  ScoreScrabble
//
//  Created by Ezekiel Williams on 7/7/17.
//  Copyright © 2017 Ezekiel Williams. All rights reserved.
//

#include "Game.hpp"

Game::Game()
{    
}

void Game::Intro()
{
    std::cout << "Playing some Scrabble?\nI'll score for you!\n";
    
    // TODO some ascii art
    
    std::cout << "All I need to know is how many people will be playing." << std::endl;
}

void Game::EnterNPlayers() { // used in InitializeGame() function
    std::cout << "Number of players = ";
    
    char input[5];
    int NPlayers = 0;
    do {
        std::cin.getline(input, 5);
        NPlayers = atoi(input);
        if (!NPlayers)
            std::cout << "Enter a number please: ";
        else if (NPlayers < 2 || NPlayers > 4)
            std::cout << "Only 1-4 players: ";
    } while (!NPlayers || (NPlayers < 2 || NPlayers > 4));
    
    std::cout << std::endl;
    nPlayers = static_cast<unsigned short int>(NPlayers);
    return;
}

void Game::InitializePlayers() {
    players.reserve(nPlayers);
    for (int i = 0; i < nPlayers; ++i) {
        players.push_back(Player(i + 1));
    }
    return;
}

void Game::EnterNames() {
    std::string tempName = "";
    std::cout << "Decide who is going first, then enter your names.\n\n";
    for (int i = 0; i < nPlayers; ++i) {
        // player i+1 enter your name and so on
        std::cout << "Player " << (i + 1) << ", enter your name: ";
        std::getline(std::cin, tempName);
        players[i].SetName(tempName);
    }
}

void Game::GameLoop() {
    Intro();
    EnterNPlayers();
    InitializePlayers();
    EnterNames();
    std::cout << "Okay players, lets begin!\n" << std::endl;
    bool isQuit = false;
    do {
        DisplayPlayers();
        //for each player, take their turn
        //until someone quits
        for (int i = 0; i < nPlayers; ++i) {
            isQuit = players[i].TakeTurn();
            if (isQuit)
                break;
        }
    } while (!isQuit);
    
    for (int i = 0; i < nPlayers; ++i) {
        players[i].EndGameCalcs();
        players[i].ShowStats();
    }
}

void Game::DisplayPlayers() const {
    for (int i = 0; i < nPlayers; ++i) {
        if (i != 0) {
            std::cout << "  ||  ";
        }
        std::cout << players[i].GetName() << " -> Score: " << players[i].GetScore();
    }
    std::cout << "\n";
    for (int i = 0; i < nPlayers; ++i) {
        std::cout << "***********************";
    }
    std::cout << std::endl << std::endl;
}
