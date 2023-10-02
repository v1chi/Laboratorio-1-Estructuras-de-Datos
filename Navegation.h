#pragma once
#include <bits/stdc++.h>
#include "Software.h"
using namespace std;

class Navegation: public Software
{
    private:
    string* historial;
    
    public:
    Navegation(string name, string developer, int price);
    ~Navegation();
    void addPage(string);
    string seeHistorial();
};