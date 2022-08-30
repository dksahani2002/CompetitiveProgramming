#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,m;
    cin>>n>>m;
    int g[n][m];
    int x=0,y=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]>=g[x][y]){
                x=i;
                y=j;
            }
        }
    }
    cout<<(max((x+1),(n-x))*max(y+1,m-y))<<endl;
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