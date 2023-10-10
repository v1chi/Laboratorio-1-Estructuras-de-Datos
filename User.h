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
    vector<Software*> softwares;

    public:
    User(string username, string password, int age, string mail, bool logUser);
    User();
    int getAge();
    string getUsername();
    string getPassword();
    string getMail();
    bool getLog();
    void addSoftware(Software*);
    vector<Software*> getSoftwares();
    void deleteSoftware(int position);
};


User::User(string username, string password, int age, string mail, bool logUser)
{
    this->username=username;
    this->password=password;
    this->age=age;
    this->mail=mail;
    this->logUser=logUser;
};
User::User(){};
int User::getAge(){return this->age;};
string User::getUsername(){return this->username;};
string User::getPassword(){return this->password;};
string User::getMail(){return this->mail;};
bool User::getLog(){return this->logUser;};
void User::addSoftware(Software* add)
{
    softwares.push_back(add);
};
vector<Software*> User::getSoftwares(){return this->softwares;};
void User::deleteSoftware(int position)
{
    softwares.erase(softwares.begin()+position);
};