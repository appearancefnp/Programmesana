// f1_uzdevums.cpp
// Autors: Kârlis Jçkabsons; kj18028
// Radîts: v.1.0; 08.02.2019
/******************************************************
F1. Dots teksta fails f. Uzrakstît programmu, kura
atrod failâ f visus vârdus, kas ir apakðvirkne
dotajai virknei m. Izvadît ðos vârdus failâ f1.
Par vârdu uzskatît patvaïîgu simbolu virkni, kas
atdalîta ar tukðumiem vai pieturas zîmçm (punkts,
komats, apaïâs iekavas, izsaukuma zîme, jautâjuma
zîme). Drîkst uzskatît, ka vârda garums nepârsniedz 40.
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
    while (pos < rin.size()) {                                      //Izciklç cauri visiem rindas simboliem
        while (!isBadChar(rin[pos]) && pos < rin.size()) {          //Veido vârdu
            vards+=rin[pos];
            pos++;
        };
        if (isBadChar(rin[pos]) || pos+1 > rin.size()) {            //Pârbauda vai nav slikts simbols
            if (vards.size() > 0 && input.find(vards) != string::npos) {    //Pârbauda vai vârds ietilpst simbolu virknç
                addToFile(vards, output);
            }
            vards="";
            while (isBadChar(rin[pos]) && pos < rin.size()) {       //Atrod nâkamâ vârda sâkumu
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
    cout << "Programma meklçs failâ vârdus pçc lietotâja pieprasîjuma." << endl;
    cout << "Ja jûsu dotajâ apakðvirknç ir atrasts vârds, tad tas tiks izvadîts \"f1.txt\" failâ" << endl;
    fin.open("f.txt");
    fout.open("f1.txt");
    if (!fin) {
        cout << endl << "Fails netika atrasts!" << endl;
        return 3;
    } else {
        cout << endl <<"Fails atrasts!" << endl;
    }
    cout << endl << "Lûdzu ievadiet virkni: ";
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
