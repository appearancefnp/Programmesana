#include <iostream>
#include "../../G_uzdevums/kartot.h"
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
bool compareLists(node* first1, node* first2) {


    while ((first1 != NULL) || (first2 != NULL)) {
        if (!(first1 != NULL && first2 != NULL)) return false;
        if (first1->info != first2->info) return false;
        first1 = first1->next;
        first2 = first2->next;
    }
    return true;
}
void test1(node* sortedlistFirst) {
    node* randlistFirst=NULL;
    node* randlistLast=NULL;
    addElementToList(1, randlistFirst, randlistLast);
    addElementToList(4, randlistFirst, randlistLast);
    addElementToList(2, randlistFirst, randlistLast);
    addElementToList(3, randlistFirst, randlistLast);
    addElementToList(5, randlistFirst, randlistLast);
    kartot(randlistFirst, randlistLast);
    cout << compareLists(sortedlistFirst, randlistFirst) << endl;
    dzest(randlistFirst);
}

void test2(node* sortedlistFirst) {
    node* randlistFirst=NULL;
    node* randlistLast=NULL;
    addElementToList(1, randlistFirst, randlistLast);
    addElementToList(4, randlistFirst, randlistLast);
    addElementToList(2, randlistFirst, randlistLast);
    addElementToList(3, randlistFirst, randlistLast);
    kartot(randlistFirst, randlistLast);
    cout << !compareLists(sortedlistFirst, randlistFirst) << endl;
    dzest(randlistFirst);
}
void test3(node* sortedlistFirst) {
    node* randlistFirst=NULL;
    node* randlistLast=NULL;
    kartot(randlistFirst, randlistLast);
    cout << !compareLists(sortedlistFirst, randlistFirst) << endl;
    dzest(randlistFirst);
}
void test4(node* sortedlistFirst) {
    node* randlistFirst=NULL;
    node* randlistLast=NULL;
    addElementToList(1, randlistFirst, randlistLast);
    addElementToList(4, randlistFirst, randlistLast);
    addElementToList(2, randlistFirst, randlistLast);
    addElementToList(3, randlistFirst, randlistLast);
    addElementToList(5, randlistFirst, randlistLast);
    addElementToList(6, randlistFirst, randlistLast);
    kartot(randlistFirst, randlistLast);
    cout << !compareLists(sortedlistFirst, randlistFirst) << endl;
    dzest(randlistFirst);
}

void test5(node* sortedlistFirst) {
    node* randlistFirst=NULL;
    node* randlistLast=NULL;
    addElementToList(5, randlistFirst, randlistLast);
    addElementToList(4, randlistFirst, randlistLast);
    addElementToList(3, randlistFirst, randlistLast);
    addElementToList(2, randlistFirst, randlistLast);
    addElementToList(1, randlistFirst, randlistLast);
    kartot(randlistFirst, randlistLast);
    cout << compareLists(sortedlistFirst, randlistFirst) << endl;
    dzest(randlistFirst);
}


int main() {
    node* sortedlistFirst=NULL;
    node* sortedlistLast=NULL;

    addElementToList(1, sortedlistFirst, sortedlistLast);
    addElementToList(2, sortedlistFirst, sortedlistLast);
    addElementToList(3, sortedlistFirst, sortedlistLast);
    addElementToList(4, sortedlistFirst, sortedlistLast);
    addElementToList(5, sortedlistFirst, sortedlistLast);

    //TEST

    test1(sortedlistFirst);     //P�rbauda vai sak�rtotais saraksts ir vien�ds ar patval�gu sarakstu
    test2(sortedlistFirst);     //P�rbauda vai da��di saraksti nesakr�t
    test3(sortedlistFirst);     //P�rbauda vai sak�rtots saraksts nav vien�ds ar tuk�u sarakstu
    test4(sortedlistFirst);     //P�rbauda vai da��da izm�ra saraksti nesakr�t
    test5(sortedlistFirst);     //P�rbauda vai apgriezts saraksts ir vien�ds ar doto

    //TEST END

    dzest(sortedlistFirst);
    return 0;
}
