//
//  Player.hpp
//  ScoreScrabble
//
//  Created by Ezekiel Williams on 1/1/17.
//  Copyright © 2017 Ezekiel Williams. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include <map>



class Player
{
private:
    std::string Name;
    int Score, Turn, Number;
    double AvgScore, AvgWordLength;
    std::list<std::string> Words;
    std::map<char, int> Letters;
    char MostCommonLetter;
    
public:
    Player(int number);
    
public:
    //gets and sets
    int GetScore() const;
    void SetScore(int score);
    std::string GetName() const;
    int GetNumber() const;
    void SetName(std::string newName);
    //play time functions
    bool TakeTurn(); // bool to check if quit on turn
    void EnterScore();
    void ConvertWordToLower(std::string&);
    void EndGameCalcs();
    char FindCommonLetter();
    void ShowStats() const;
};


#endif /* Player_hpp */
