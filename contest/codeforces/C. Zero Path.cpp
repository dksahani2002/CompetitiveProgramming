#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int g[1001][1001];
int dp[1001][1001];
bool rec(int i, int j, int sum){
    if(i>=n || j>=m)return false;
     sum+=g[i][j];
    if(i==n-1 && j==m-1 && sum==0){
         return true; 

    }
    bool ans=0;
    if(dp[i][j]!=-1)return dp[i][j];
    ans=rec(i,j+1,sum ) || rec(i+1,j,sum );
    return dp[i][j]= ans;
}
void solve()

{
    
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
     
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    bool tr=rec(0,0,0);
    //   for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(tr){
        cout<<"Yes\n";

    }else{
        cout<<"No\n";
    }
    
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