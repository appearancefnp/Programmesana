#include<iostream>
#include "eq.h"
using namespace std;
int main() {
    int x,y;
    cin>>x>>y;
    try {
        cout<<eq(x,y)<<endl;
    }
    catch(const char *msg) {
        cout<<msg<<endl;
    }
}
