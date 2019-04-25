#include<iostream>
#include "../equation/eq.h"
using namespace std;
void test1() {
 cout<<(eq(1,2)==0)<<endl;
}
void test2() {
 cout<<(eq(10,2)==3)<<endl;
}
void test3() {
    try {
        eq(10,-4);
    }
    catch(const char *s) {
        cout<<1<<endl;
    }
    catch(...) {
        cout<<"Wrong Error thrown OK"<<endl;
    }
}
int main()
{
    test1();
    test2();
    test3();
}
