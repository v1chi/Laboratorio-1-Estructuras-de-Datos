#pragma once
#include <iostream>
#include "Software.h"
using namespace std;

class Security: public Software
{
    private:
    string type;

    public:
    Security(string name, string developer, int price, string type);
    string getType();
};


//------------------------------METODOS-------------------------------------
Security::Security(string name, string developer, int price, string type):Software(name, developer, price)
{
    this->type=type;
};
string Security::getType(){return this->type;};
