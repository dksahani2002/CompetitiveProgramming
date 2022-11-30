#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,d;
    cin>>n>>d;
     vector<string>dp(n);
     int vis[n][n];
     memset(vis,0,sizeof(vis));
    deque<pair<int,pair<int,int>>>dq;
    for(int i=0;i<n;i++){
        cin>>dp[i];
        for(int j=0;j<dp[i].size();j++){
            if(dp[i][j]=='#'){
                dq.push_back({d,{i,j}});
                vis[i][j]=1;
            }
        }
    }
 
    while (!dq.empty()) {
 
    //     int d = dq.front().first;
    //     int x = dq.front().second.first;
    //     int y = dq.front().second.second; 
    //     dq.pop_front(); 
    //     // if(dp[x][y]=='x'){
    //     //     continue;
    //     // }
    //     vis[x][y]=1;
    //     dp[x][y]='x';
    //   if(d && x+1<n && !vis[x+1][y]) dq.push_front({d-1,{x+1,y}});
    //   if(d && x-1>=0 && !vis[x-1][y]) dq.push_front({d-1,{x-1,y}});
    //   if(d && y+1<n && !vis[x][y+1]) dq.push_front({d-1,{x,y+1}});
    //   if(d && y-1>=0 && !vis[x][y-1]) dq.push_front({d-1,{x,y-1}});
    //   if(d-2>0 && y-1>=0 && x-1>=0) dq.push_front({d-2,{x-1,y-1}});
    //   if(d-2>0 && y+1<n && x+1<n) dq.push_front({d-2,{x+1,y+1}});
    //   if(d-2>0 && y+1<n && x-1>=0) dq.push_front({d-2,{x-1,y+1}});
    //   if(d-2>0 && y-1>=0 && x+1<n) dq.push_front({d-2,{x+1,y-1}}); 
}
for(int i=0;i<n;i++)cout<<dp[i]<<endl;
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