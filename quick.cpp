#include<bits/stdc++.h>
using namespace std;
int partition(int low,int high,vector<int>& arr)
{
    int i=low-1;
    int pivot=arr[high];
    for(int j=low;j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quicks(int low,int high,vector<int>& arr)
{
    if(low<high)
    {
        int part=partition(low,high,arr);
        quicks(low,part-1,arr);
        quicks(part+1,high,arr);
    }
}
int r_partition(int low,int high,vector<int>& arr)
{
    int randm=low+rand()%(high-low);
    swap(arr[randm],arr[high]);
    partition(low,high,arr);
}
void quick_r(int low,int high,vector<int>& arr)
{
    if(low<high)
    {
        int part=r_partition(low,high,arr);
        quicks(low,part-1,arr);
        quicks(part+1,high,arr);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];


    cout<<"1.Deterministic Quick Sort"<<endl;
    cout<<"2.Randomized Quick Sort"<<endl;

    int ch;
    cin>>ch;

    if(ch==1)
    quicks(0,n-1,arr);
    else
    quick_r(0,n-1,arr);
    for(auto i:arr)
    cout<<i<<" ";
}