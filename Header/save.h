#include<iostream>
bool save_kho = 1;
bool save_ncc = 1;
bool save_PN = 1;
bool save_dsPN = 1;
inline bool save(){
    return save_kho && save_ncc && save_PN && save_dsPN;
}

