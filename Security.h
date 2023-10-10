#pragma once
#include <iostream>
#include "Software.h"
using namespace std;

class Security: public Software
{
    private:
    string type;

    public:
    Security(string name, string developer, int price, bool forUnderage, string type);
    string getType();
    string toString();
};


//------------------------------METODOS-------------------------------------
Security::Security(string name, string developer, int price, bool forUnderage, string type):Software(name, developer, price, forUnderage)
{
    this->type=type;
};
string Security::getType(){return this->type;};
string Security::toString()
{
    return "Tipo: Software de Seguridad, Nombre: " + getName() + ", Developer: " + getDeveloper() + ", Precio: " + to_string(getPrice()) + "Tipo de Seguridad: "+ type + "\n";
};