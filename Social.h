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
};


//--------------------------------------METODOS--------------------------------------------
Social::Social(string name, string developer, int price, bool forUnderage):Software(name, developer, price, forUnderage){ this->friendsCount = 0;};
void Social::addFriend()
{   
    this->friendsCount += 1;
    cout << "Amigo añadido exitosamente" << endl;
};
