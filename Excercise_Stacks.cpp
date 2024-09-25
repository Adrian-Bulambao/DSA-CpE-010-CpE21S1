#include <iostream>
#include <stack>
using namespace std;

void display (stack<string>pl)
{
    while(!pl.empty())
    {
    cout<<pl.top()<<"\n";
    pl.pop();
    }
}


int main()
{
    stack <string> pl;
    //add items into stack
    pl.push("c++ ");
    pl.push("Java ");
    pl.push("Python ");
    cout<<"Initial stack: "<<endl;
    display (pl);
    pl.pop();
    pl.pop();
    cout<<"\n"<<"Final stack: "<<endl;
    display (pl);
    return 0;
}

