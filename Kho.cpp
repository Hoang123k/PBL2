#include "Kho.h"
Kho::Kho(){}
Kho::~Kho(){}
void Kho::show(){
    for(int i=0;i<this->soluonghang;i++){
        this->kho[i].show();
    }
}