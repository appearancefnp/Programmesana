// g1_uzdevums.cpp
/// Autors: K�rlis J�kabsons; kj18028
// Rad�ts: v.1.0; 22.02.2019
// V.1.1; 23.02.2019
//      Salabots k�rto�anas algoritms, jo pirmstam no list pazuda elementi
// V.1.2; 26.02.2019
//      Pievienots STL list
/******************************************************
G1. Uzrakst�t funkciju, kas sak�rto sarakstu t� elementu
pieaug�anas sec�b�. Darb�ba j�veic, p�rkabinot saites,
nevis p�rkop�jot elementu v�rt�bas.
*******************************************************/

#include <iostream>
#include <list>
#include "lvfriendly.h"
using namespace std;

void printlist(list<int> s) {
    if (s.begin() == s.end()) {
        cout << "Saraksts ir tuk�s!" << endl;
        return;
    }
    for (auto i = s.begin(); i != s.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

void addElementToList(int info, list<int> &saraksts){
    if (!cin.good()) throw "ERROR: Ievad�ts nepareizs datu tips!";
    saraksts.push_back(info);
    return true;
}


int main() {
    list<int> saraksts;
    int info,ok=1;
    do {
        cout << "Programma �aus izveidot patva��gu veselu skait�u sarakstu, izdruk�t to augo�� sec�b�." << endl;
        cout << "Lai p�rtrauktu saraksta veido�anu, ievadiet ne skaitlisku simbolu." << endl;
        do {
            cin >> info;
            try {
                addElementToList(info, saraksts);
            }
            catch(const char* txt) {
                cout << txt << endl;
            }
        } while (cin.good());
        cin.clear();
        cin.ignore(1024, '\n');

        saraksts.sort();
        //Izdruk�t un iztuk�ot STL list
        cout << "Sak�rtots augo�� sec�b� (STL list):    ";
        printlist(saraksts);
        saraksts.clear();
        cout << endl << "Atk�rtot (1) vai Beigt(0): ";
        cin >> ok;
    } while(ok == 1);
    return 0;
}

//////////////////TESTA PL�NS/////////////////////////////////
///IEVADE                             PAREDZAMAIS IZN�UKMS
/// -5 41 51 7 0                       -5 0 7 41 51
/// 51 16 0 21 4                        0 4 16 21 51
/// neievada neko                       "Saraksts ir tuk�s!"
//////////////////////////////////////////////////////////////
