#pragma once
#include <bits/stdc++.h>
#include "Software.h"
using namespace std;

class Navegation: public Software
{
    private:
    vector<string> historial;
    
    public:
    Navegation(string name, string developer, int price, bool isForUnderage);
    void addPage(string url);
    void seeHistorial();
    string toString();
};


//----------------------------------------------------------------METODOS-------------------------------------------------------------
Navegation::Navegation(string name, string developer, int price, bool isForUnderage):Software(name, developer, price, isForUnderage)
{
    vector<string> historial;
};

void Navegation::addPage(string url)
{
    this->historial.push_back(url);
};
void Navegation::seeHistorial()
{   
    
    if(this->historial.size() <= 0){
        cout <<  "No existe historial" << endl;
    }
    else if(this->historial.size() <= 10){
        for (int i = 0; i < this->historial.size(); i++){
            cout << this->historial[i] << endl;
        }
    }
    else if(this->historial.size() > 10){
        for (int i = this->historial.size() - 10; i < this->historial.size(); i++){
            cout << this->historial[i] << endl;
        }
    }
};
string Navegation::toString()
{
    return "Tipo: Software de Navegacion, Nombre: " + getName() + ", Developer: " + getDeveloper() + ", Precio: " + to_string(getPrice());
};