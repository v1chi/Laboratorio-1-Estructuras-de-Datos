#pragma once
#include <iostream>
#include "Software.h"
using namespace std;

class Security: public Software
{
    private:
    string type;

    public:
    Security(string name, string developer, int price, bool isForUnderage, string type);
    string getType();
};


//------------------------------METODOS-------------------------------------
Security::Security(string name, string developer, int price, string type, bool isForUnderage):Software(name, developer, price, isForUnderage)
{
    this->type=type;
};
string Security::getType(){return this->type;};
