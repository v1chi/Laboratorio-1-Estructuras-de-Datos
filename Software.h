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
    bool forUnderage;

    int price;

    public:
    Software(string name, string developer, int price, bool forUnderage);
    string getName();
    string getDeveloper();
    int getPrice();
    bool isForUnderage();
    string toString();

};


//------------------------------METODOS-------------------------------------
Software::Software(string name, string developer, int price, bool forUnderage)
{
    this->name=name;
    this->developer=developer;
    this->price=price;
    this->forUnderage=forUnderage;
};
string Software::getName(){return this->name;};
string Software::getDeveloper(){return this->developer;};
int Software::getPrice(){return this->price;};
bool Software::isForUnderage(){return this->forUnderage;};
string Software::toString()
{
    return "Nombre: " + name + ", Developer: " + developer + ", Precio: " + to_string(price) + "\n";
};