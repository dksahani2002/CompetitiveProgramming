#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m;
vector<int>f,b;
int rec(int i,int nn, int mm){
    if(i>=(n+m)){
        if(nn==0 && mm==0)return 0;
        return 1e9;
    }
    int ans=1e9;
    return min(f[i]+rec(i+1,nn-1,mm),b[i]+rec(i+1,nn,mm-1));
}
void solve()
{
    cin>>n>>m;
    f.clear();f.resize(n+m);
    b.clear();b.resize(n+m);
    for(int i=0;i<n+m;i++)cin>>f[i];
    for(int i=0;i<n+m;i++)cin>>b[i];
    cout<<rec(0,n,m); 
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