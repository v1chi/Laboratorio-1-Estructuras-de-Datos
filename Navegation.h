#pragma once
#include <bits/stdc++.h>
#include "Software.h"
using namespace std;

class Navegation: public Software
{
    private:
    vector<string> historial;
    
    public:
    Navegation(string name, string developer, int price);
    void addPage(string url);
    string seeHistorial();
};