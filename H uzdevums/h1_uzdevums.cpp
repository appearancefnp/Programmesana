///Autors: Kârlis Jçkabsons (kj18028)
//Izveidots: 13.03.2019
/***********************************************************************************
H1. Dots teksta fails. Atrast tekstâ visbieþâk lietotos vârdus,
kas sâkas ar a, b, c utt. (katram latîòu alfabçta burtam, neðíirojot
reìistru). Programmai vârdi jâsaliek tabulâ, kas realizçta kâ vârdnîca
(STL map), kur pçc pirmâ burta glabâjas visi vârdi, kas sâkas ar ðo burtu.
Vârdu saraksts, kas sâkas ar doto burtu, arî ir vârdnîca, kas  katram
vârdam glabâ tâ sastapto reiþu skaitu tekstâ. Programmas rezultâtâ iegût
failu, kurâ katram latîòu alfabçta burtam (a..z) izdrukâts bieþâk sastopamais
vârds un tâ sastapðanas reiþu skaits tekstâ (piemçram, and 101, but 18, captain 9 utt.).
Par vârdu tiek uzskatîta latîòu alfabçta burtu virkne.
***********************************************************************************/

#include <fstream>
#include <iostream>
#include <map>
#include <iomanip> //setw
using namespace std;

void vardiUzVardnicu(string rinda, map<string,int> &m) {
    ////////// ATROD VÂRDUS UN TOS PIEVIENO VÂRDNÎCAI AR SKAITÎTÂJU///////////
    for(int i=0;i<rinda.length();i++) {
        if(isalpha(rinda[i]) and (i==0 or !isalpha(rinda[i-1]))) {
        //Ja i-tais ir burts un (i-1)-ais nav atstarpe, sâkam veidot vârdu
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
            //Pievieno vardu>0 failam, ja mainâs burts
            if (vards.size() > 0) {
                fout << left << setw(16) << vards << setw(3) << lielakais << endl;
                vards="";
                lielakais=0;
            }
        }
        //Iestata bieþâk sastopamo vârdu uz alfabçta burta
        if (i.first[0] == burts) {
            if (i.second > lielakais) {
                lielakais = i.second;
                vards = i.first;
            }
        }
    }
    //Pievieno pçdçjo elementu
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
