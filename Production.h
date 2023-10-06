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
};


//------------------------------METODOS-------------------------------------
Production::Production(string name, string developer, int price, bool isForUnderage, string type):Software(name, developer, price, isForUnderage)
{
    this->type=type;
};
string Production::getType(){return this->type;};