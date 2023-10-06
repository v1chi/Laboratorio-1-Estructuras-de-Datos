#pragma once
#include <bits/stdc++.h>
#include "Software.h"
#include "User.h"
using namespace std;

class Social: public Software
{
    private:
    vector<User*> friends;

    public:
    Social(string name, string developer, int price);
    void addFriend(User* user);
    void deleteFriend(User* user);
    void seeFriends*();
};


//--------------------------------------METODOS--------------------------------------------
Social::Social(string name, string developer, int price):Software(name, developer, price){};
void Social::addFriend(User* user)
{
    this->friends.push_back(user);
    vector<User*> friends;
};
void Social::deleteFriend(User* user)
{  
    for(int i=0; i<this->friends.size(); i++){
        if(this->friends[i]->getUsername() == user->getUsername())
        {
            this->friends.erase(this->friends.begin(),this->friends.begin()+i);
            cout << "Uusario eliminado con exito" << endl;
            return;
        }
    }
    cout << "No se pudo eliminar al usuario ya que no se encuentra en su lista de amigos" << endl;
};
void Social::seeFriends()
{
    for(int i=0; i<this->friends.size(); i++){
        cout << this->friends[i]->getUsername() << endl;
    }
};