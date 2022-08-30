#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        v[i]-=k;
        if(i)v[i]+=v[i-1];
    }
    map<int,int>mp;
    int ans=0;
    for(int i=0;i<n;i++){
        if(v[i]==0){
            ans++;
        }
        if(mp.find(v[i])!=mp.end()){
            ans+=mp[v[i]];
        }
        mp[v[i]]++;
    }
    cout<<ans<<endl;
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