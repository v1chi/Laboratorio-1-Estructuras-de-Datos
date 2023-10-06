#pragma once
#include <bits/stdc++.h>
#include "Software.h"
using namespace std;

class OfficeAutomation: public Software
{
    private:
    int fileCount;
    
    public:
    OfficeAutomation(string name, string developer, int price);
    void createFile();
    bool deleteFile();

};