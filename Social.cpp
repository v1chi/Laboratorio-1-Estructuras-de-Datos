#include <bits/stdc++.h>
#include "Software.h"
#include "Social.h"
#include "User.h"
using namespace std;


Social::Social(string name, string developer, int price):Software(name, developer, price){};

void Social::addFriend(User* user)
{
    this->friends.push_back(user);
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