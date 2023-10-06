#pragma once
#include <bits/stdc++.h>
#include <string>
#include "User.h"
using namespace std;

class Software
{
    private:
    string name;
    string developer;
    bool isForUnderage;

    int price;

    public:
    Software(string name, string developer, int price, bool isForUnderage);
    string getName();
    string getDeveloper();
    int getPrice();
    bool isForUnderage();
    //virtual tostring

};


//------------------------------METODOS-------------------------------------
Software::Software(string name, string developer, int price, bool isForUnderage)
{
    this->name=name;
    this->developer=developer;
    this->price=price;
    this->isForUnderage=isForUnderage;
};
string Software::getName(){return this->name;};
string Software::getDeveloper(){return this->developer;};
int Software::getPrice(){return this->price;};
bool Software::isForUnderage(){return this->isForUnderage;};