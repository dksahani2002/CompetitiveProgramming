#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<int>dd;
bool rec(int i,int left){
    if(i>=dd.size()){
        return left==0;
    }
    if(left==0)return 1;
    bool ans=false;
    if(dd[i]==0){
        return rec(i+2,left-1) || rec(i+1,left);
    }
    return rec(i+2,left);
}
void solve()
{
    int n,k;cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    dd=v;
    if(rec(0,k)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
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