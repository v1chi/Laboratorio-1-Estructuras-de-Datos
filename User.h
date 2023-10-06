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
    vector<Software> softwares;

    public:
    User(string username, string password, int age, string mail, bool log);
    int getAge();
    string getUsername();
    string getPassword();
    string getMail();
    bool getLog();
    vector<Software> getSoftwares();
};




User::User(string username, string password, int age, string mail, bool log)
{
    this->username=username;
    this->password=password;
    this->age=age;
    this->mail=mail;
    this->log=log;
};
int User::getAge(){return this->age;};
string User::getUsername(){return this->username;};
string User::getPassword(){return this->password;};
string User::getMail(){return this->mail;};
bool User::getLog(){return this->log;};
//vector<Software*> User::getSoftwares(){return this->softwares;};