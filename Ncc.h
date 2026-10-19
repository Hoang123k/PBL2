#pragma once
#include<iostream>
using namespace std;
class Ncc{
    private:
        string mancc;
        string tenncc;
        string sdtncc;
        string diachincc;
    public:
        Ncc();
        Ncc(const string, const string,
        const string, const string);
        ~Ncc();

        string getmancc();
        string gettenncc();
        string getsdtncc();
        string getdiachincc();

        void setmancc(string);
        void settenncc(string);
        void setsdtncc(string);
        void setdiachincc(string);

};