#include <iostream>
using namespace std;
int main(){
    int a, b, c;
    cout<<"Enter 2 nos";
    cin>>a>>b;
    try{
        if(b==0)
        throw b;
        else{
            c=a/b;
            cout<<"Result"<<c;
            throw;
        }
    }
    catch(int x){
        cout<<"Can't divide by"<<x;
    }
    return 0;
}