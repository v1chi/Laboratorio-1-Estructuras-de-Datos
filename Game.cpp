#include <bits/stdc++.h>
#include "Software.h"
#include "Game.h"
using namespace std;


Game::Game(string name, string developer, int price, string genre):Software(name, developer, price)
{
    this->genre=genre;
};
string Game::getGenre(){return this->genre;};