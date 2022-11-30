#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<vector<int>>g;
    int n,m;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void dfs(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m || g[i][j]!=0)return;
    g[i][j]=-1;
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0 && x<n && y>=0 && y<m && g[x][y]==0)dfs(x,y);
    }
}
void solve()
{
    cin>>n>>m;
    g.clear();
    g.resize(n,vector<int>(m));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        char x;cin>>x;
        if(x=='.')g[i][j]=0;
        else g[i][j]=1;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]==0){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<endl;
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