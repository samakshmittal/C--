#include <iostream>
using namespace std;
void div(int x, int y){
    cout<<"Inside function";
    try{
        if(y==0)
        throw y;
        else{
            cout<<"Result"<<x/y;
        }
    }
    catch(int x){
        cout<<"Caught inside function";
        throw;
    }
    cout<<"End";
}
int main(){
    cout<<"Inside main()";
    try{
        div(10,5);
        div(20,0);
    }
    catch (int a){
        cout<<"Caught inside int function";
    }
    cout<<"End";
    return 0;
}