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
    string mail;
    bool log;
    //vector<Software*> softwares;

    public:
    User(string username, string password, int age, string mail, bool log);
    int getAge();
    string getUsername();
    string getPassword();
    string getMail();
    bool getLog();
    //vector<Software*> getSoftwares();
};