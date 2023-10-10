#pragma once
#include <bits/stdc++.h>
#include <string>
#include "User.h"
using namespace std;

class Software
{
    private:
    string name;
    string developer;
    bool forUnderage;
    vector<string> users;

    int price;

    public:
    Software();
    Software(string name, string developer, int price, bool forUnderage);
    string getName();
    string getDeveloper();
    int getPrice();
    bool isForUnderage();
    vector<string> getUsers();
    void addUser(string user);
    void deleteUser(string user);
    virtual string toString();

};


//------------------------------METODOS-------------------------------------
Software::Software(){};
Software::Software(string name, string developer, int price, bool forUnderage)
{
    this->name=name;
    this->developer=developer;
    this->price=price;
    this->forUnderage=forUnderage;
};
string Software::getName(){return this->name;};
string Software::getDeveloper(){return this->developer;};
int Software::getPrice(){return this->price;};
bool Software::isForUnderage(){return this->forUnderage;};
vector<string> Software::getUsers(){return this->users;};
void Software::addUser(string user)
{
    users.push_back(user);
};
void Software::deleteUser(string user)
{
    int position = -1;
    for(int i = 0; i < users.size(); i++){
        if(users[i] == user){
            position = i;
            break;
        }
    }
    if(position != -1){
        users.erase(users.begin()+position);
    }
    else{
        cout << "No se pudo eliminar" << endl;
    }
};
string Software::toString()
{
    return "Nombre: " + name + ", Developer: " + developer + ", Precio: " + to_string(price);
};