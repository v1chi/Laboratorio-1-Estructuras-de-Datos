#include <bits/stdc++.h>
#include "Software.h"
#include "Security.h"
using namespace std;


Security::Security(string name, string developer, int price, string type):Software(name, developer, price)
{
    this->type=type;
};
string Security::getType(){return this->type;};
