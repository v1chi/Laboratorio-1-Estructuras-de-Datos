#pragma once
#include <iostream>
#include "User.h"
using namespace std;

class UserChild: public User
{
    public:
    UserChild(string username, string password, int age);
    ~UserChild();
};