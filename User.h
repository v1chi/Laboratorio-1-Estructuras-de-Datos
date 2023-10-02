#pragma once
#include <bits/stdc++.h>
#include "Software.h"
using namespace std;

class User
{
    private:
    string username;
    string password;
    int age;
    //vector<Software> softwares;

    public:
    User(string username, string password, int age);
    ~User();
    int getAge();
    string getUsername();
    string getPassword();
    //vector<Software> getSoftwares();
};