#include <bits/stdc++.h>
#include "Software.h"
#include "Navegation.h"
using namespace std;


Navegation::Navegation(string name, string developer, int price):Software(name, developer, price)
{

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