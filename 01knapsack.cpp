// #include<bits/stdc++.h>
// using namespace std;
// // int f(int index,vector<int>& wt,vector<int>& val,int W,vector<vector<int>>& dp)
// // {
// //    if(index==0)
// //    {
// //     if(wt[0]<=W)
// //     return val[0];
// //     else
// //     return 0;
// //    }
// //    if(dp[index][W]!=-1)
// //    return dp[index][W];
// //     int nontake=0+f(index-1,wt,val,W,dp);

// //     int take=INT_MIN;
// //     if(wt[index]<=W)
// //     take=val[index]+f(index-1,wt,val,W-wt[index],dp);

// //     return dp[index][W]=max(take,nontake);
   
// // }
// int main()
// {
//     int W=5;
//     int n;
//     cin>>n;
//     vector<int>wt(n);
//     vector<int>val(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>wt[i];
//     }
//     for(int i=0;i<n;i++)
//     {
//         cin>>val[i];
//     }

//     //vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
//     //cout<<f(n,wt,val,W,dp);
//     vector<vector<int>>dp(n+1,vector<int>(W,0));

//     for(int i=wt[0];i<=W;i++)
//     dp[0][i]=val[0];

//     for(int i=1;i<n;i++)
//     {
//         for(int w=0;w<=W;w++)
//         {
//             int nontake=dp[i-1][w];
//             int take=INT_MIN;
//             if(wt[i]<=w)
//             {
//                 take=val[i]+dp[i][w-wt[i]];
//             }
//             dp[i][w]=max(take,nontake);
//         }
//     }
//     cout<<dp[n-1][W];


// }
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int W=5;
    vector<int>wt(n);
    vector<int>val(n);
    for(int i=0;i<n;i++)
    cin>>wt[i];

    for(int i=0;i<n;i++)
    cin>>val[i];

    
    vector<vector<int>>dp(n+1,vector<int>(W,0));
    for(int i=wt[0];i<=W;i++)
    dp[0][i]=val[0];

    for(int i=1;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            int nontake=dp[i-1][w];
            int take=INT_MIN;
            if(wt[i]<=w)
            {
               take=val[i]+dp[i-1][w-wt[i]];
            }

            dp[i][w]=max(take,nontake);
        }
    }

    cout<<dp[n][W];
}