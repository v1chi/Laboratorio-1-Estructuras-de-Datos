#pragma once
#include <bits/stdc++.h>
#include "Software.h"
using namespace std;

class Game: public Software
{
    private:
    string genre;
    
    public:
    Game(string name, string developer, int price, string genre);
    string getGenre();
};


Game::Game(string name, string developer, int price, string genre):Software(name, developer, price)
{
    this->genre=genre;
};
string Game::getGenre(){return this->genre;};