// Online C++ compiler to run C++ program online
#include <iostream>
#include <thread>
using namespace std;
void threadfn(){
    cout<<"Inside thread"<<endl;
}
int main(){
    thread t1(threadfn);
    t1.join();
    return 0;
}