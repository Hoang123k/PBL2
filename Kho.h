#pragma once
#include "Hanghoa.h"
#include<vector>
#include<string.h>
class Kho{
    public:
        int soluonghang;
        vector<Hanghoa> kho;
    public:
        Kho();
        ~Kho();
        // cac ham qli 
        void show();
        friend void docfile(Kho&, const string&);

};