#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n;
void solve()
{
    cin>>n;
    vector<int>ind(n+1);
    int ans=0;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        ind[u]++;
        ind[v]++;
        ans=max(ans,ind[u]);
        ans=max(ans,ind[v]);
    }
    cout<<ans+1<<endl;

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