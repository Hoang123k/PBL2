#include "Ncc.h"
#include<fstream>
#include<sstream>
Ncc::Ncc(){}
Ncc::~Ncc(){}
Ncc::Ncc(const string mancc, const string tenncc,
    const string sdtncc, const string diachincc)
        : mancc(mancc), tenncc(tenncc), sdtncc(sdtncc), diachincc(diachincc) {}

// GETTER
string Ncc::getmancc(){
    return this->mancc;
}
string Ncc::gettenncc(){
    return this->tenncc;
}
string Ncc::getsdtncc(){
    return this->sdtncc;
}
string Ncc::getdiachincc(){
    return this->diachincc;
}

// SETTER

void Ncc::setmancc(string mancc){
    this->mancc = mancc;
}
void Ncc::settenncc(string tenncc){
    this->tenncc = tenncc;
}
void Ncc::setsdtncc(string sdtncc){
    this->sdtncc = sdtncc;
}
void Ncc::setdiachincc(string diachincc){
    this->diachincc = diachincc;
}
