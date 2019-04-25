///Autors: K�rlis J�kabsons (kj18028)
//Izveidots: 13.03.2019
/***********************************************************************************
H1. Dots teksta fails. Atrast tekst� visbie��k lietotos v�rdus,
kas s�kas ar a, b, c utt. (katram lat��u alfab�ta burtam, ne��irojot
re�istru). Programmai v�rdi j�saliek tabul�, kas realiz�ta k� v�rdn�ca
(STL map), kur p�c pirm� burta glab�jas visi v�rdi, kas s�kas ar �o burtu.
V�rdu saraksts, kas s�kas ar doto burtu, ar� ir v�rdn�ca, kas  katram
v�rdam glab� t� sastapto rei�u skaitu tekst�. Programmas rezult�t� ieg�t
failu, kur� katram lat��u alfab�ta burtam (a..z) izdruk�ts bie��k sastopamais
v�rds un t� sastap�anas rei�u skaits tekst� (piem�ram, and 101, but 18, captain 9 utt.).
Par v�rdu tiek uzskat�ta lat��u alfab�ta burtu virkne.
***********************************************************************************/

#include <fstream>
#include <iostream>
#include <map>
#include <iomanip> //setw
using namespace std;

void vardiUzVardnicu(string rinda, map<string,int> &m) {
    ////////// ATROD V�RDUS UN TOS PIEVIENO V�RDN�CAI AR SKAIT�T�JU///////////
    for(int i=0;i<rinda.length();i++) {
        if(isalpha(rinda[i]) and (i==0 or !isalpha(rinda[i-1]))) {
        //Ja i-tais ir burts un (i-1)-ais nav atstarpe, s�kam veidot v�rdu
            string vards="";
            while(isalpha(rinda[i])) {
                  vards+=tolower(rinda[i]);
                  i++;
            }
            m[vards]+=1;
        }
    }
}
void BiezosVardusUzFailu(const map <string,int> &m, ofstream &fout) {
    int lielakais = 0;
    char burts = 'a';
    string vards="";

    for (const auto &i :m) {
        // Alfabetiski parbauda vai ir tads vards
        if (i.first[0] != burts) {
            //Maina burtu, lidz atrod vardu ar tadu sakumburtu
            do {
                burts = char(((int)burts)+1);
            } while (i.first[0] != burts);
            //Pievieno vardu>0 failam, ja main�s burts
            if (vards.size() > 0) {
                fout << left << setw(16) << vards << setw(3) << lielakais << endl;
                vards="";
                lielakais=0;
            }
        }
        //Iestata bie��k sastopamo v�rdu uz alfab�ta burta
        if (i.first[0] == burts) {
            if (i.second > lielakais) {
                lielakais = i.second;
                vards = i.first;
            }
        }
    }
    //Pievieno p�d�jo elementu
    fout << left << setw(16) << vards << setw(3) << lielakais << endl;
}

int main() {
    string rin;
    map<string,int> m;
    ofstream fout;
    ifstream fin;
    fout.open("out.txt");
    fin.open("in.txt");
    if (!fin) {
        cout << "Fails \"in.txt\"netika atrasts!" << endl;
        return 3;
    } else {
        cout << "Fails \"in.txt\" atrasts!" << endl;
    }

    while (getline(fin, rin)) {
        vardiUzVardnicu(rin, m);
    }
    BiezosVardusUzFailu(m, fout);
    fout.close();
    fin.close();
    return 0;
}
////////////////////////TESTA PLANS/////////////////////////////////////////
//Ieeja                                            //Izeja (https://planetcalc.com/3205/)
//Alfa, Bravo, Charlie, Delta, Echo,               Katrs vards vienu reizi
//Foxtrot, Golf, Hotel, India, Juliett,
//Kilo, Lima, Mike, November, Oscar,
//Papa, Quebec, Romeo, Sierra, Tango,
//Uniform, Victor, Whiskey, Xray, Yankee, Zulu.
////////////////////////////////////////////////////////////////////////////
//But I must explain to you how all this             and             3
//mistaken idea of denouncing pleasure and           because         2
//praising pain was born and I will give you         complete        1
//a complete account of the system, and expound      denouncing      1
//the actual teachings of the great explorer of      encounter       1
//the truth, the master-builder of human             give            1
//happiness. No one rejects, dislikes, or            how             2
//avoids pleasure itself, because it is              i               2
//pleasure, but because those who do not             master          1
//know how to pursue pleasure rationally             no              1
//encounter consequences that are extremely painful. of              5
//                                                   pleasure        4
//                                                   rationally      1
//                                                   system          1
//                                                   the             5
//                                                   was             1
//                                                   you             2
