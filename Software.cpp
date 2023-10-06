#include <bits/stdc++.h>
#include "User.h"
#include "Software.h"
using namespace std;

Software::Software(string name, string developer, int price)
{
    this->name=name;
    this->developer=developer;
    this->price=price;
    
};
void Software::setAgeClassification(bool underage){this->underage=underage;};
string Software::getName(){return this->name;};
string Software::getDeveloper(){return this->developer;};
int Software::getPrice(){return this->price;};
//vector<User*> Software::getUsers(){return this->users;};