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
    //vector<User> users;
    int price;

    public:
    Software(string name, string developer, int price);
    void setAgeClassification(bool underage);
    string getName();
    string getDeveloper();
    int getPrice();
    //get users

};