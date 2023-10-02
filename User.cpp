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

User::User(string username, string password, int age)
{
    this->username=username;
    this->password=password;
    this->age=age;
    //vector<Software> softwares;
};
User::~User(){};
int User::getAge(){return this->age;};
string User::getUsername(){return this->username;};
string User::getPassword(){return this->password;};
//SoftwareSinglyLinkedList* User::getSoftwares(){return this->softwares;};