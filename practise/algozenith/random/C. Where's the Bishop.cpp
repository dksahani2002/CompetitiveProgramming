#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n=8;
    vector<string>dp(n);
    for(int i=0;i<n;i++){
         cin>>dp[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i-1>=0 && j-1>=0 && i+1<n && j+1<n){
                if(dp[i][j]=='#' && dp[i-1][j-1]=='#' && dp[i-1][j+1]=='#' && dp[i+1][j+1]=='#' && dp[i+1][j-1]=='#'){
                    cout<<i+1<<" "<<j+1<<endl;
                    return;
                }
            }
           
        }
    }
    // vector<int>v(n);
    // map<int,int>mp;
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    //     mp[v[i]]++;
    // }
    // if((n-mp.size())%2==0){
    //     cout<<mp.size()<<endl;
    // }else{
    //     cout<<mp.size()-1<<endl;
    // }
//     int a,b,c,d;
//     cin>>a>>b>>c>>d;
//     int cnt=0;
//      if(b>a)cnt++; 
//      if(c>a)cnt++;
//      if(d>a)cnt++;
//      cout<<cnt<<endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}