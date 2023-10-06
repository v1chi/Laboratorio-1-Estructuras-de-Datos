#pragma once
#include <bits/stdc++.h>
#include "Software.h"
using namespace std;

class OfficeAutomation: public Software
{
    private:
    int fileCount;
    
    public:
    OfficeAutomation(string name, string developer, int price, bool isForUnderage);
    void createFile();
    bool deleteFile();
    string getCount();

};


//---------------------------------------------------------METODOS------------------------------------------------------------------------------
OfficeAutomation::OfficeAutomation(string name, string developer, int price,bool isForUnderage):Software(name, developer, price, isForUnderage){};
void OfficeAutomation::createFile()
{
    this->fileCount += 1;
    cout << "Se ha agregado un archivo con éxito" << endl;
};
bool OfficeAutomation::deleteFile()
{
    if(this->fileCount == 0){ 
        cout << "No tiene archivos para eliminar" << endl; 
        return false;
    }
    this->fileCount -= 1;
    cout << "Se ha eliminado un archivo con éxito" << endl;
    return true;
};
string OfficeAutomation::getCount()
{
    return "Este software tiene " << this->getCount() << " archivos\n";
};