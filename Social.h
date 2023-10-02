#pragma once
#include <bits/stdc++.h>
#include "Software.h"
#include "User.h"
using namespace std;

class Social: public Software
{
    private:
    User* friends;

    public:
    Social(string name, string developer, int price);
    ~Social();
    void addFriend(string);
    void deleteFriend(string);
};