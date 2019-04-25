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
#include "kartot.h"
#include "lvfriendly.h"
using namespace std;

void print(node* p) {
    if (p == NULL) {
        cout << "Saraksts ir tuks�!" << endl;
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
    if (!cin.good()) throw "ERROR: Ievad�ts nepareizs datu tips!";
    //Linked-list izveido�ana un papildin��ana
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
        cout << "Programma �aus izveidot patva��gu veselu skait�u sarakstu, izdruk�t to augo�� sec�b�." << endl;
        cout << "Lai p�rtrauktu saraksta veido�anu, ievadiet ne skaitlisku simbolu." << endl;
        do {
            cin >> info;
            try {
                addElementToList(info, first, last);
            }
            catch(const char* txt) {
                cout << txt << endl;
            }
        } while (cin.good());            // Cikl�jam l�dz kam�r neievada sliktu simbolu
        cin.clear();
        cin.ignore(1024, '\n');

        cout << "J�s ievad�j�t: ";
        print(first);
        kartot(first, last);
        //Izdruk�t un iztuk�ot linked list
        cout << "Sak�rtots augo�� sec�b� (linked-list): ";
        print(first);
        dzest(first);

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
