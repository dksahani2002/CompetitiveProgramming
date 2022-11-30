#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v,tm(n+3,0);
    map<int,vector<int>>mp;
    v.push_back(1e9);
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        v.push_back(x);
        mp[x].push_back(i);
    }
    v.push_back(1e9);
    int ans=0;
    int time=1;
    for(auto x:mp){
        for(auto i:x.second){
            tm[i]=time;
            if(v[i]>v[i-1]){
                int temp=tm[i-1];
                tm[i]=max(tm[i],1+temp);
            }
            if(v[i]>v[i+1]){
                int temp=tm[i+1];
                tm[i]=max(tm[i],1+temp);
            }
        }
    }
    for(int i=0;i<n+3;i++)ans+=tm[i];
    cout<<ans<<endl;
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