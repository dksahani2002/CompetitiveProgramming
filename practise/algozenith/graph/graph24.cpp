#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m;
vector<vector<int>>g;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dis[1001][1001];
void rec(int i, int j){

    deque<pair<int,int>>dq;
    dq.push_front({i,j});
    while(!dq.empty()){
        auto p=dq.front();dq.pop_front();
         i=p.first;
         j=p.second;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=n || x<0 || y>=m || y<0 )continue;
            if(g[i][j]==k){
                if(dis[x][y]>dis[i][j]){
                    dis[x][y]=dis[i][j];
                    // rec(x,y);
                    dq.push_front({x,y});
                }
            }else{
                if(dis[x][y]>1+dis[i][j]){
                    dis[x][y]=1+dis[i][j];
                    // rec(x,y);
                    dq.push_back({x,y});
                }
            }
        }
    // return ans;
    }
}
void solve()
{
    cin>>n>>m;
    g.clear();
    g.resize(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            g[i][j]--;
            dis[i][j]=1e9;
        }
    }
    dis[0][0]=0;
    rec(0,0);
    cout<<dis[n-1][m-1]<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
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