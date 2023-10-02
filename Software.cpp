#include <bits/stdc++.h>
#include "Software.h"
#include "User.h"
using namespace std;

Software::Software(string name, string developer, int price)
{
    this->name=name;
    this->developer=developer;
    this->price=price;
    
};
Software::~Software(){};
void Software::setLegalAge(bool underage){this->underage=underage;};
string Software::getName(){return this->name;};
string Software::getDeveloper(){return this->developer;};
int Software::getPrice(){return this->price;};
//UserSinglyLinkedList* Software::getUsers(){return this->users;};