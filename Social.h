#pragma once
#include <bits/stdc++.h>
#include "Software.h"
#include "User.h"
using namespace std;

class Social: public Software
{
    private:
    int friendsCount;

    public:
    Social(string name, string developer, int price, bool forUnderage);
    void addFriend();
    string toString();
};


//--------------------------------------METODOS--------------------------------------------
Social::Social(string name, string developer, int price, bool forUnderage):Software(name, developer, price, forUnderage){ this->friendsCount = 0;};
void Social::addFriend()
{   
    this->friendsCount += 1;
    cout << "Amigo añadido exitosamente" << endl;
};
string Social::toString()
{
    return "Tipo: Software Social, Nombre: " + getName() + ", Developer: " + getDeveloper() + ", Precio: " + to_string(getPrice()) + "\n";
};