#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,m;
    cin>>n>>m;
    int g[n][m],v[n][m]={0};
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]==2){
                q.push({i,j});
                v[i][j]=0;
            }else{
                v[i][j]=1e9;
            } 
        }
    }
    int ans=0;
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second; 
        q.pop();
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<n && y>=0 && y<m && v[x][y]==1e9 &&  g[x][y]!=0){ 
                    v[x][y]=1+v[i][j];
                    q.push({x,y});  
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // cout<<v[i][j]<<" ";
            if(v[i][j]==1e9 && g[i][j]==1){
                cout<<-1<<endl;
                return;
            }
            if(v[i][j]<1e9)ans=max(ans,v[i][j]);
        }
        // cout<<endl;
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