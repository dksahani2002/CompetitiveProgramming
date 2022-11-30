#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
vector<pair<int,int>>g;
int rec(int i, int hero){
    if(hero<=0)return 0;
    if(i>=g.size())return hero>=1;
    bool ans=false;
    if(v[i].second==1'){
        ans=rec(i+1,hero+v[i].first-1) || rec(i+1,hero);
    }else{
        ans=rec(i+1,hero-v[i].first);
    }
    return ans;
}
void solve()
{
    int n;cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;
    g=v;
    cout<<rec(0,1)<<endl;
}
signed main()
{
    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}