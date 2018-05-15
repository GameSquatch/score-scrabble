//
//  Player.cpp
//  ScoreScrabble
//
//  Created by Ezekiel Williams on 1/1/17.
//  Copyright © 2017 Ezekiel Williams. All rights reserved.
//

#include "Player.hpp"


int Player::GetScore() const { return Score; }
void Player::SetScore(int score) { Score = score; }
void Player::SetName(std::string newName) { Name = newName; }
std::string Player::GetName() const { return Name; }
int Player::GetNumber() const { return Number; }

Player::Player(int number)
    : Name("Player"), Score(0), AvgScore(0.0), AvgWordLength(0.0), MostCommonLetter('e'), Turn(0), Number(number)
{
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        Letters[ch] = 0;
    }
}

bool Player::TakeTurn()
{
    std::string Word = "";
    


    std::cout << Name << "\nEnter your word ('QUIT' to finish): "; // enter the word
    getline(std::cin, Word);
    
    if (Word == "QUIT") // check to see if the last word was QUIT to exit
    {
        return true; // returns true to 'is the game quit?' if 'QUIT' was entered
    }
    
    ConvertWordToLower(Word);
    Words.push_front(Word); // push word to front and point an iterator at the beginning
    for (int i = 0; i < Word.length(); ++i) {//add letter counts to the map
        Letters[Word[i]]++;
    }
    
    std::cout << "Score: ";
    EnterScore();
    
    std::cout << std::endl;
    Turn++;
    
    return false;
}

void Player::EnterScore()
{
    int TempScore = 0;
    const int INPUT_CHARS = 10;
    do
    {
        char input[INPUT_CHARS];
        std::cin.getline(input, INPUT_CHARS);
        TempScore = atoi(input);
        if (TempScore == 0)
            std::cout << "Enter a number: ";
    } while (TempScore == 0);
    Score += TempScore;
    
    return;
}

void Player::ConvertWordToLower(std::string& Word)
{
    for (int i = 0; i < Word.length(); i++)
    {
        Word[i] = tolower(Word[i]);
    }
}

void Player::EndGameCalcs()
{
    if (Turn) {
        // avg score calc
        AvgScore = ((double)Score)/Turn;
    
    
        // most used letter calc
        std::list<std::string>::iterator WordsIter;
        int WordLengths(0);
    
        //sum all word lengths for a player
        for (WordsIter = Words.begin(); WordsIter != Words.end(); WordsIter++)
        {
            std::string Word = *WordsIter;
            WordLengths += Word.length();
        }
    
    
        // average word length
        if (Words.size() == 0)
        {
            AvgWordLength = 0.0;
        }
        else
        {
            AvgWordLength = ((double)WordLengths/Words.size());
        }
    
    
        // find the most common letter in the map
        MostCommonLetter = FindCommonLetter();
    
        
    } else {
        return;
    }
    return;
}

char Player::FindCommonLetter() {
    int greatest(0);
    char most = Letters.begin()->first;
    std::map<char, int>::iterator letterIter;
    
    for (letterIter = Letters.begin(); letterIter != Letters.end(); letterIter++)
    {
        if (letterIter->second > greatest)
        {
            most = letterIter->first;
            greatest = letterIter->second;
        }
    }
    
    return most;
}

void Player::ShowStats() const
{
    std::cout << "\n\n" << Name << std::endl;
    std::cout << "Total score = " << Score << std::endl;
    std::cout << "Average score per word = " << AvgScore << std::endl;
    std::cout << "Average word length = " << AvgWordLength << std::endl;
    std::cout << "Most commonly used letter = " << MostCommonLetter << std::endl;
    std::cout << std::endl;
    return;
}


