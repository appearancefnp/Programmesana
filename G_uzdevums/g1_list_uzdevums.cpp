// g1_uzdevums.cpp
/// Autors: Kârlis Jçkabsons; kj18028
// Radîts: v.1.0; 22.02.2019
// V.1.1; 23.02.2019
//      Salabots kârtoðanas algoritms, jo pirmstam no list pazuda elementi
// V.1.2; 26.02.2019
//      Pievienots STL list
/******************************************************
G1. Uzrakstît funkciju, kas sakârto sarakstu tâ elementu
pieaugðanas secîbâ. Darbîba jâveic, pârkabinot saites,
nevis pârkopçjot elementu vçrtîbas.
*******************************************************/

#include <iostream>
#include <list>
#include "lvfriendly.h"
using namespace std;

void printlist(list<int> s) {
    if (s.begin() == s.end()) {
        cout << "Saraksts ir tukðs!" << endl;
        return;
    }
    for (auto i = s.begin(); i != s.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

void addElementToList(int info, list<int> &saraksts){
    if (!cin.good()) throw "ERROR: Ievadîts nepareizs datu tips!";
    saraksts.push_back(info);
    return true;
}


int main() {
    list<int> saraksts;
    int info,ok=1;
    do {
        cout << "Programma ïaus izveidot patvaïîgu veselu skaitïu sarakstu, izdrukât to augoðâ secîbâ." << endl;
        cout << "Lai pârtrauktu saraksta veidoðanu, ievadiet ne skaitlisku simbolu." << endl;
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
        //Izdrukât un iztukðot STL list
        cout << "Sakârtots augoðâ secîbâ (STL list):    ";
        printlist(saraksts);
        saraksts.clear();
        cout << endl << "Atkârtot (1) vai Beigt(0): ";
        cin >> ok;
    } while(ok == 1);
    return 0;
}

//////////////////TESTA PLÂNS/////////////////////////////////
///IEVADE                             PAREDZAMAIS IZNÂUKMS
/// -5 41 51 7 0                       -5 0 7 41 51
/// 51 16 0 21 4                        0 4 16 21 51
/// neievada neko                       "Saraksts ir tukðs!"
//////////////////////////////////////////////////////////////
