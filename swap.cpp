#include <iostream>
using namespace std;
int main(){
    int a=1, b=2;
    int c=b;
    b=a;
    a=c;
    cout<<"a="<<a<<" b="<<b;
    return 0;
}