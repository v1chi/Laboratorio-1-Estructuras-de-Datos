#pragma once
#include <iostream>
#include "Software.h"
using namespace std;

class Production: public Software
{
    private:
    string type;

    public:
    Production(string name, string developer, int price, bool isForUnderage, string type);
    string getType();
    string toString();
};


//------------------------------METODOS-------------------------------------
Production::Production(string name, string developer, int price, bool isForUnderage, string type):Software(name, developer, price, isForUnderage)
{
    this->type=type;
};
string Production::getType(){return this->type;};
string Production::toString()
{
    return "Tipo: Software de Produccion, Nombre: " + getName() + ", Developer: " + getDeveloper() + ", Precio: " + to_string(getPrice()) + "Tipo de Produccion: "+ type + "\n";
};