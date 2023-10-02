#pragma once
#include <iostream>
#include "User.h"
using namespace std;

class UserAdmin: public User
{
    private:
    string mail;

    public:
    UserAdmin(string username, string password, int age, string mail);
    ~UserAdmin();
    string getMail();
};