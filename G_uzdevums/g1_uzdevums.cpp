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
#include "kartot.h"
#include "lvfriendly.h"
using namespace std;

void print(node* p) {
    if (p == NULL) {
        cout << "Saraksts ir tuksð!" << endl;
        return;
    }
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

void dzest(node* &p) {
    node* q = p;
    while (p != NULL) {
        q = p->next;
        delete p;
        p = q;
    }
}

void addElementToList(int info, node* &first, node* &last) {
    if (!cin.good()) throw "ERROR: Ievadîts nepareizs datu tips!";
    //Linked-list izveidoðana un papildinâðana
    node* p = new node;
    p->info=info;
    p->next=NULL;
    if (first == NULL) {
        first = p;
    } else {
        last->next=p;
    }
    last = p;
}

int main() {
    node* first=NULL;
    node* last=NULL;
    int info, ok=1;
    do {
        cout << "Programma ïaus izveidot patvaïîgu veselu skaitïu sarakstu, izdrukât to augoðâ secîbâ." << endl;
        cout << "Lai pârtrauktu saraksta veidoðanu, ievadiet ne skaitlisku simbolu." << endl;
        do {
            cin >> info;
            try {
                addElementToList(info, first, last);
            }
            catch(const char* txt) {
                cout << txt << endl;
            }
        } while (cin.good());            // Ciklçjam lîdz kamçr neievada sliktu simbolu
        cin.clear();
        cin.ignore(1024, '\n');

        cout << "Jûs ievadîjât: ";
        print(first);
        kartot(first, last);
        //Izdrukât un iztukðot linked list
        cout << "Sakârtots augoðâ secîbâ (linked-list): ";
        print(first);
        dzest(first);

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
