#pragma once
#include <bits/stdc++.h>
#include "Software.h"
using namespace std;

class Game: public Software
{
    private:
    string genre;
    
    public:
    Game(string name, string developer, int price, bool isForUnderage, string genre);
    string getGenre();
    string toString();
};

//------------------------------------------------------------METODOS------------------------------------------------------------------
Game::Game(string name, string developer, int price, bool isForUnderage, string genre):Software(name, developer, price, isForUnderage)
{
    this->genre=genre;
};
string Game::getGenre(){return this->genre;};
string Game::toString()
{
    return "Tipo: Software de Juego, Nombre: " + getName() + ", Developer: " + getDeveloper() + ", Precio: " + to_string(getPrice()) + "Genero: "+ genre + "\n";
};