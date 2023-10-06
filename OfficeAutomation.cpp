#include <bits/stdc++.h>
#include "Software.h"
#include "OfficeAutomation.h"
using namespace std;


OfficeAutomation::OfficeAutomation(string name, string developer, int price, int fileCount):Software(name, developer, price)
{
    this->fileCount = fileCount;
};
void OfficeAutomation::createFile()
{
    this->fileCount += 1;
    cout << "Se ha agregado un archivo con éxito" << endl;
};
bool OfficeAutomation::deleteFile()
{
    if(this->fileCount == 0){ cout << "No tiene archivos para eliminar" << endl; }
    else{
        this->fileCount -= 1;
        cout << "Se ha eliminado un archivo con éxito" << endl;
    }
};
