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
    ~Game();
    string getGenre();
};