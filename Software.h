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
    bool underage;
    //vector<User*> users;
    int price;

    public:
    Software(string name, string developer, int price);
    void setAgeClassification(bool underage);
    string getName();
    string getDeveloper();
    int getPrice();
    //vector<User*> getUsers();
    //virtual tostring

};


//------------------------------METODOS-------------------------------------
Software::Software(string name, string developer, int price)
{
    this->name=name;
    this->developer=developer;
    this->price=price;
    //vector<User*> users;
    
};
void Software::setAgeClassification(bool underage){this->underage=underage;};
string Software::getName(){return this->name;};
string Software::getDeveloper(){return this->developer;};
int Software::getPrice(){return this->price;};
//vector<User*> Software::getUsers(){return this->users;};