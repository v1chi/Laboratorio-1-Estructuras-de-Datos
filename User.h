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
    bool logUser;
    vector<vector<Software>> softwares;

    public:
    User(string username, string password, int age, string mail, bool logUser);
    int getAge();
    string getUsername();
    string getPassword();
    string getMail();
    bool getLog();
    vector<vector<Software>> getSoftwares();
};




User::User(string username, string password, int age, string mail, bool logUser)
{
    this->username=username;
    this->password=password;
    this->age=age;
    this->mail=mail;
    this->logUser=logUser;
    vector<Software> softwares(6);
};
int User::getAge(){return this->age;};
string User::getUsername(){return this->username;};
string User::getPassword(){return this->password;};
string User::getMail(){return this->mail;};
bool User::getLog(){return this->logUser;};
vector<vector<Software>> User::getSoftwares(){return this->softwares;};