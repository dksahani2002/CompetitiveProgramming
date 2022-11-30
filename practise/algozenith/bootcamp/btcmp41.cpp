#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
vector<vector<int>>v;
int n;
int rec(int i,vector<int>vis,int cnt){
    if(cnt==n)return 1;
    vis[i]=1;
    int ans=0;
    for(int j=1;j<=9;j++){
        if(!vis[j] && (v[i][j]==0 || vis[v[i][j]])){
            ans+=rec(j,vis,cnt+1);
        }
    }
    return ans;
}
void solve()
{
    cin>>n;
    v.resize(10,vector<int>(10,0));
    v[1][3]=v[3][1]=2;
    v[1][7]=v[7][1]=4;
    v[3][9]=v[9][3]=6;
    v[7][9]=v[9][7]=8;
    v[1][9]=v[9][1]=v[2][8]=v[8][2]=v[3][7]=v[7][3]=v[4][6]=v[6][4]=5;
    vector<int>vis(10,0);
    int ans=4*rec(1,vis,1);
    ans+=4*rec(2,vis,1);
    ans+=rec(5,vis,1);
    cout<<ans<<endl;

}
signed main()
{
    fast;
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}