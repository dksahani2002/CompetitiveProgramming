#include<bits/stdc++.h>
using namespace std;
int bfs(int grid[][m+1],bool vis[][m+1])
int main(){
    int t;cin>>t;
    while(t--){
        int m,n,k,x,y;
        cin>>m>>n>>k>>x>>y;
        int grid[m][m];
        memset(grid,0,sizeof(grid));
        while(k--){
            int i,j;
            cin>>i>>j;
            grid[i][j]=-1;
        }
        bool vis[m+1][m+1];
        memset(vis,false , sizeof(vis));
         int ans = bfs(grid , vis , x,y , n);
         cout<<ans<<endl;
    }
}