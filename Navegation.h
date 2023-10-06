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
    vector<string> historial(10);
    for(int i = 0; i < 10; i++){
        this->historial.push_back(NULL);
    }
};

void Navegation::addPage(string url)
{
    this->historial.push_back(url);
};
string Navegation::seeHistorial()
{   
    string url = "";
    for (int i = 0; i < this->historial.size(); i++){
        url += this->historial[i] + "\n";
    }
    return url;
};