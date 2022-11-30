#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n;
vector<string>g;
vector<vector<int>>vis;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void dfs(int i,int j,int &pr,int &ar){
        ar++;
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x<0 || x>=n || y<0 || y>=n || g[x][y]=='.'){
                pr++;
                continue;
            }else if(!vis[x][y]){
                dfs(x,y,pr,ar);
            }
        }
}
bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.first==b.first)return a.second<b.second;
    return a.first>b.first;

}
void solve()
{
    cin>>n;
    g.clear();
    g.resize(n);
    vis.clear(); 
    vis.resize(n,vector<int>(n,0));
    for(int i=0;i<n;i++)cin>>g[i];
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] && g[i][j]=='#'){
                int pr=0,ar=0;
                dfs(i,j,pr,ar);
                v.push_back({ar,pr});
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    
    cout<<v[0].first<<" "<<v[0].second<<endl;
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