#pragma once
#include "Hanghoa.h"
#include<vector>
class Kho{
    public:
        int soluonghang;
        vector<Hanghoa> kho;
    public:
        Kho();
        ~Kho();
        // cac ham qli 
        void show();
};