#include<iostream>
using namespace std;
class Num{
    public:
    static int i;
    Num(){cout<<i++<<" ";}
    };
    int Num::i=1;
    int main(){
        int n;
        cout<<"Enter value on n :: ";
        cin>>n;
        cout<<"\n";
        Num obj[n];
        cout<<"\n";
        return 0;
        }