#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
int n;
vector<vector<int>>v;
int rec(int i,set<int>st,bool hap){
    if(i>=n)return (hap || st.size()==n );
    int ans=0;
    for(int j=0;j<n;j++){
        if(st.count(j))continue;
        if(v[i][j]!=1)st.insert(j);
        ans+=rec(i+1,st,(v[i][j]==3)?1:hap);
    }
    return ans;
}
void solve()
{
    cin>>n;
    v.clear();
    v.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    set<int>st;
    int ans=rec(0,st,0);
    cout<<ans<<endl;
     
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