#pragma once
#include <bits/stdc++.h>
#include "Software.h"
#include "User.h"
using namespace std;

class Social: public Software
{
    private:
    vector<string> friends;

    public:
    Social(string name, string developer, int price);
    void addFriend(string user);
    void deleteFriend(string user);
};

Social::Social(string name, string developer, int price):Software(name, developer, price){};

void Social::addFriend(string user)
{
    this->friends.push_back(user);
};

void Social::deleteFriend(string user)
{  
    for(int i=0; i<this->friends.size(); i++){
        if(this->friends[i].getUsername() == user)
        {
            this->friends.erase(this->friends.begin(),this->friends.begin()+i);
            cout << "Uusario eliminado con exito" << endl;
            return;
        }
    }
    cout << "No se pudo eliminar al usuario ya que no se encuentra en su lista de amigos" << endl;
};