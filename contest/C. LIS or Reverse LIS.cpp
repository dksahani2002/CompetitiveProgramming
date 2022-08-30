#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
    int n;cin>>n;
     vector<int>v(n),temp;
     map<int,int>mp;
     for(int i=0;i<n;i++){
         cin>>v[i];
         mp[v[i]]++; 
     }
     int ans=0;
    for(auto i:mp){
        if(i.second==1)ans++;
        else ans+=2;
    }
     cout<<((ans+1)/2) <<endl;
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
