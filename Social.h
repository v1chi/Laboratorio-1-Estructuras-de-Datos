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
void Social::addFriend(User friend)
{   
    this->friends.push_back(friend);
};

