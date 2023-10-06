#include <bits/stdc++.h>
#include "Software.h"
#include "Production.h"
using namespace std;


Production::Production(string name, string developer, int price, string type):Software(name, developer, price)
{
    this->type=type;
};
string Production::getType(){return this->type;};