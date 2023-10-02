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
    ~Security();
    string getType();
};