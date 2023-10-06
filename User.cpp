#include <bits/stdc++.h>
#include "User.h"
#include "Software.h"
using namespace std;


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