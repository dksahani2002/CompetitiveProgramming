#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,m;cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            if(i && j && v[i][j])v[i][j]+=min({v[i-1][j],v[i][j-1],v[i-1][j-1]});
            ans=max(ans,v[i][j]*v[i][j]);
        }
    }
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