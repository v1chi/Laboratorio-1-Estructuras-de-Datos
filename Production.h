#pragma once
#include <iostream>
#include "Software.h"
using namespace std;

class Production: public Software
{
    private:
    string type;

    public:
    Production(string name, string developer, int price, string type);
    string getType();
};