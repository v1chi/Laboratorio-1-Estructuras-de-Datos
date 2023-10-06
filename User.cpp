#include <bits/stdc++.h>
#include "User.h"
#include "Software.h"
using namespace std;

/*
    User(string username, string password, int age);
    ~User();
    int getAge();
    string getUser();
    string getPassword();
    Software getUserSoftwares();
*/

User::User(string username, string password, int age, string mail, bool log)
{
    this->username=username;
    this->password=password;
    this->age=age;
    this->mail=mail;
    this->log=log;
    //vector<Software> softwares;
};
int User::getAge(){return this->age;};
string User::getUsername(){return this->username;};
string User::getPassword(){return this->password;};
//SoftwareSinglyLinkedList* User::getSoftwares(){return this->softwares;};