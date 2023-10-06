#pragma once
#include <bits/stdc++.h>
#include "Software.h"
using namespace std;

class OfficeAutomation: public Software
{
    private:
    int fileCount;
    vector<string> files;
    
    public:
    OfficeAutomation(string name, string developer, int price, int fileCount);
    void createFile(string file);
    bool deleteFile(string file);

};