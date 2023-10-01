#pragma once
#include <iostream>
#include "Software.h"
#include "SoftwareSinglyLinkedList.h"
using namespace std;

class User
{
    private:
    string user;
    string password;
    int age;
    SoftwareSinglyLinkedList* softwares;

    public:
    User(string, string, int);
    ~User();
    int getAge();
    string getUser();
    string getPassword();
};