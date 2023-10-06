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
    string seeHistorial();
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
string Navegation::seeHistorial()
{   
    string url = "";
    
    if(this->historial.size() <= 0){
        url = "No existe historial" << endl;
    }
    else if(this->historial.size() <= 10){
        for (int i = 0; i < this->historial.size(); i++){
            if(this->historial[i] != NULL){
                url += this->historial[i] + "\n";
            }
        }
    }
    else if(this->historial.size() > 10){
        for (int i = this->historial.size() - 10; i < this->historial.size(); i++){
            url += this->historial[i] + "\n";
        }
    }

    return url;
    
    
};