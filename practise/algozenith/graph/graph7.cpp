#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<vector<char>>g;
vector<vector<int>>vis;
int n,kk;
void update(){
    for(int j=0;j<10;j++){
        int k=n-1;
        for(int i=n-1;i>=0;i--){
            if(g[i][j]!='0'){
                swap(g[k][j],g[i][j]);
                k--;
            }
        }
    }

}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void dfs(int i,int j, int &sz, char xx){
    sz++;
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0 && x<n && y>=0 && y<10 && g[x][y]==xx && !vis[x][y]){
            dfs(x,y,sz,xx);
            // cout<<"jokpsfjp"<<endl;
        }
    }
}
void bfs(int i,int j, char xx){
    g[i][j]='0';
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0 && x<n && y>=0 && y<10 && g[x][y]==xx){
            bfs(x,y,xx);
        }
    }
}
void solve()
{
    cin>>n>>kk;
    g.clear();
    g.resize(n,vector<char>(10));
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++)cin>>g[i][j];
    }
    update();
    while(true){
        vis.clear();
        vis.assign(n,vector<int>(10,0));
        int flag=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<10;j++){
                
                if(!vis[i][j] && g[i][j]!='0'){
                    int sz=0;
                    dfs(i,j,sz,g[i][j]);
                    // cout<<sz<<endl;
                    if(sz>=kk){
                        flag=0;
                        bfs(i,j,g[i][j]);
                        update();
                    }
                }
            }
        }
        if(flag)break;
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++)cout<<g[i][j];
        cout<<endl;
    }
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