#include "eq.h"
int division(int a,int b) {
    if(b==0) throw "ERR";
    return a/b;
}
int eq(int a, int b) {
    return division(a,1+division(5,b));
}
