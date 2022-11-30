#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

void solve()
{
    map<int,int>cube;

    int n;cin>>n;
    vector<int>v(n);
    int ending=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        ending=max(ending,v[i]);
    }
    for(int i=1;i*i*i<=ending;i++){
        cube[i*i*i]++;
    }

    map<int,int>mp;
    sort(v.rbegin(),v.rend());
    int ans=0,extra=0;
    for(int i=0;i<n;i++){
        if(cube.count(v[i]))extra++;
        if(mp.count(v[i]*v[i])){
           if(!cube.count(v[i])) ans+=mp[v[i]*v[i]];
        }
        mp[v[i]]++;
    }
    extra=(extra*(extra-1))/2;
    cout<<ans+extra<<endl;
}
signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}