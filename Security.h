#pragma once
#include <iostream>
#include "Software.h"
using namespace std;

class Security: public Software
{
    private:
    string type;

    public:
    Security(string name, string developer, int price, bool forUnderage, string type);
    string getType();
};


//------------------------------METODOS-------------------------------------
Security::Security(string name, string developer, int price, bool forUnderage, string type,):Software(name, developer, price, isforUnderage)
{
    this->type=type;
};
string Security::getType(){return this->type;};
