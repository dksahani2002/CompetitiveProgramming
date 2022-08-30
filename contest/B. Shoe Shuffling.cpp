#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
     int n;cin>>n;
     vector<int>v(n);
     map<int,int>mp;
     for(int i=0;i<n;i++){
         cin>>v[i];
        mp[v[i]]++;
     }
     for(auto i:mp){
         if(i.second==1){
             cout<<-1<<endl;
             return;
         }
     }
     vector<int>ans;
    int j=1;
     for(auto i:mp){
         int l=j;j++;
         for(int k=0;k<i.second-1;k++){
             cout<<j<<" ";
             j++;
         }
        cout<<l<<" "; 
     }
     cout<<endl;
    return;
}

signed main()
{
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}