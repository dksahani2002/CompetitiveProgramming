#include <bits/stdc++.h>
using namespace std;
#define int long long
int res,sz;
int n,m,q;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void  bfs(int x,int y,vector<vector<int>>&g,int l){
     if(x<0 || x>=n || y<0 || y>=m || g[x][y]==0)return;
     g[x][y]=l;
     sz++;
     for(int k=0;k<4;k++){
        int i=x+dx[k];
        int j=y+dy[k];
       if(i>=0 && j>=0 && i<n && j<m && g[i][j]==1){
         g[i][j]=l;
         bfs(i,j,g,l);
       }
     }
    
}
void solve()
{
    cin>>n>>m>>q;
    vector<vector<int>>g(n,vector<int>(m));
    res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]==1)res++;
        }
    }
    unordered_map<int,int>mp;
    int l=2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]==1){
                sz=0;
                bfs(i,j,g,l);
                mp[l]=sz;
                l++;
            }
        }
    }
    set<int>st;
    while(q--){
        int x,y;
        cin>>x>>y;
        x--;y--;
       if(g[x][y]!=0){
        if(st.count(g[x][y])>0){

        }else{

            res-=mp[g[x][y]];
        }
        st.insert(g[x][y]);
       }
       cout<<res<<endl;

    }
     
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}