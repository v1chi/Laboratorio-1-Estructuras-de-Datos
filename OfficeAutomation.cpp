#include <bits/stdc++.h>
#include "Software.h"
#include "OfficeAutomation.h"
using namespace std;


OfficeAutomation::OfficeAutomation(string name, string developer, int price):Software(name, developer, price){};
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
