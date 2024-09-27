#include <iostream>
#include <queue>
using namespace std;

void display (queue<string>pl)
{
    while(!pl.empty())
    {
    cout<<pl.front()<<"\n";
    pl.pop();
    }
}


int main()
{
    queue <string> pl;
    //add items into stack
    pl.push("c++ ");
    pl.push("Java ");
    pl.push("Python ");
    cout<<"Initial queue: "<<endl;
    display (pl);
    pl.pop();
    pl.pop();
    cout<<"\n"<<"Final queue: "<<endl;
    display (pl);
    return 0;
}

