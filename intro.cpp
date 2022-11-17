#include <iostream>
#include <list>
using namespace std;
class YouTubeChannel{
    public:
    string Name;
    string Ownername;
    int Subscriberscount;
    list<string> PublishedVideoTitles;
};
int main(){
    YouTubeChannel ytChannel;
    ytChannel.Name="Replica";
    ytChannel.Ownername="Zebra";
    ytChannel.Subscriberscount=1400;
    ytChannel.PublishedVideoTitles={"c", "C++", "Java"};
    cout<<"Name"<<ytChannel.Name<<endl;
    cout<<"Ownername"<<ytChannel.Ownername<<endl;
    cout<<"Subscribers Count"<<ytChannel.Subscriberscount<<endl;
    cout<<"Video"<<endl;
    for(string ytChannel.PublishedVideoTitles;){
    cout<<ytChannel.PublishedVideoTitles<<endl;
    }
    system("pause>0");
}