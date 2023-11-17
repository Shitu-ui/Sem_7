#include<bits/stdc++.h>
using namespace std;
void display(vector<int>& fibb)
{
    for(auto i:fibb)
    cout<<i<<" ";
    cout<<endl;
}
void itr(int n)
{
    vector<int>fibb(n);
    fibb[0]=0;
    if(n>0)
    fibb[1]=1;
    for(int i=2;i<n;i++)
    fibb[i]=fibb[i-1]+fibb[i-2];

    display(fibb);
}
int fib(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    return fib(n-1)+fib(n-2);
}
void rec(int n)
{
    vector<int>fibb(n);
    for(int i=0;i<n;i++)
    fibb[i]=fib(i);

    display(fibb);
}
int main()
{
    int option;
    int n;
   do 
   {
    cout<<"1.Iterative"<<endl;
    cout<<"2.Recursive"<<endl;
    cout<<"3.Exit"<<endl;
    cout<<"Enter option";
    while(true)
    {
        if(!(cin>>option) || (option<1) || (option>3))
        {
            cout<<"Enter choice between 1-3";
            cin.clear();
        }
        else
        break;
    }
    if(option!=3)
    {
        cout<<"Enter number of terms";
        while(true)
        {
            if(!(cin>>n) || (n<=0))
            {
                cout<<"Enter valid term count";
                cin.clear();
            }
            else
            break;
        }
    }
    switch(option)
    {
        case 1: itr(n);
        break;
        case 2:rec(n);
        break;
        case 3:exit(0);
    }
   }while(true);
    
    
}