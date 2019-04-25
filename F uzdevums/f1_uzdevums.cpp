// f1_uzdevums.cpp
// Autors: K�rlis J�kabsons; kj18028
// Rad�ts: v.1.0; 08.02.2019
/******************************************************
F1. Dots teksta fails f. Uzrakst�t programmu, kura
atrod fail� f visus v�rdus, kas ir apak�virkne
dotajai virknei m. Izvad�t �os v�rdus fail� f1.
Par v�rdu uzskat�t patva��gu simbolu virkni, kas
atdal�ta ar tuk�umiem vai pieturas z�m�m (punkts,
komats, apa��s iekavas, izsaukuma z�me, jaut�juma
z�me). Dr�kst uzskat�t, ka v�rda garums nep�rsniedz 40.
*******************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "lvfriendly.h"
using namespace std;

bool isBadChar(char c) {
    switch(c) {
        case '.':
            return true;
        case '!':
            return true;
        case ',':
            return true;
        case '?':
            return true;
        case '(':
            return true;
        case ')':
            return true;
        case ' ':
            return true;
        default:
            return false;

    }
}

void addToFile(string vards, ofstream &output) {
    output << vards << endl;
}

void parsetRindu(string rin, string input, ofstream &output) {
    string vards="";
    int pos=0;
    while (pos < rin.size()) {                                      //Izcikl� cauri visiem rindas simboliem
        while (!isBadChar(rin[pos]) && pos < rin.size()) {          //Veido v�rdu
            vards+=rin[pos];
            pos++;
        };
        if (isBadChar(rin[pos]) || pos+1 > rin.size()) {            //P�rbauda vai nav slikts simbols
            if (vards.size() > 0 && input.find(vards) != string::npos) {    //P�rbauda vai v�rds ietilpst simbolu virkn�
                addToFile(vards, output);
            }
            vards="";
            while (isBadChar(rin[pos]) && pos < rin.size()) {       //Atrod n�kam� v�rda s�kumu
                pos++;
            };
        }
    };
    return;
}

int main() {
    ifstream fin;
    ofstream fout;
    string input,rin;
    cout << "Programma mekl�s fail� v�rdus p�c lietot�ja piepras�juma." << endl;
    cout << "Ja j�su dotaj� apak�virkn� ir atrasts v�rds, tad tas tiks izvad�ts \"f1.txt\" fail�" << endl;
    fin.open("f.txt");
    fout.open("f1.txt");
    if (!fin) {
        cout << endl << "Fails netika atrasts!" << endl;
        return 3;
    } else {
        cout << endl <<"Fails atrasts!" << endl;
    }
    cout << endl << "L�dzu ievadiet virkni: ";
    getline(cin, input);
    getline(fin, rin);
    while (fin) {
        parsetRindu(rin, input, fout);
        getline(fin, rin);
    };
    fin.close();
    fout.close();
    return 0;
}
