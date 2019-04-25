#include <fstream>
using namespace std;

struct Node {
    Node* next;
    char info[255];
};

void deleteList(Node* &first) {
    Node* deleter = first;
    while(deleter) {
        first = first->next;
        delete deleter;
        deleter = first;
    }
}

bool printListToFile(Node* first, fstream &fout, bool space) {
    bool isEmpty = true;
    if (!space && first) fout << " ";
    while(first) {
        isEmpty = false;
        fout << first->info;
        first = first->next;
        if (first) fout << " ";
    }
    return isEmpty;
}

void addToList(char* vards, Node* &first) {
    Node* newnode = new Node;
    int counter = 0;
    do {
        newnode->info[counter] = vards[counter];
        counter++;
    } while(vards[counter-1] != '\0');
    if (first) {
        newnode->next = first;
    } else {
        newnode->next = NULL;
    }
    first = newnode;
    return;
}

int main() {
    fstream fin("paldies.in", ios::in);
    fstream fout("paldies.out", ios::out);
    Node* student[26] = {NULL};
    char vards[256];
    char c;
    fin.get(c);
    while(fin) {
        int length = 0;
        if (isalpha(c)) {
            do {
                vards[length] = tolower(c);
                fin.get(c);
                length++;
            } while (isalpha(c) && !fin.eof() && length < 255);
            vards[length] = '\0';
            ///VARDS UZ LISTIEM
            int j = (int)vards[0]-97;
            addToList(vards, student[j]);
            ///VARDS AIZSUTITS UZ LISTIEM
        } else {
            do {
                fin.get(c);
            } while(!isalpha(c) && !fin.eof());
        }
    }
    bool isEmpty = true;
    for (int i = 0; i < 26; i++) {
            if(printListToFile(student[i], fout, isEmpty) == false) {
                isEmpty = false;
                deleteList(student[i]);
            }
    }
    if (isEmpty) {
        fout << "nothing";
    }
    fin.close();
    fout.close();
}
