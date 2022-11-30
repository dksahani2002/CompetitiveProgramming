#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m,d;
int cost[1010][1010];
int cal(int i);
int rec(int i,int last){
    if(i>=n)return 0;
    int ans= min(cal(i+1),rec(i+1,last)+cost[i][last]-((i)?d:0));
    // for(int j=0;j<m;j++){
    //     if(j==last && i>0){
    //         ans=min(ans,cost[i][j]-d+rec(i+1,j));
    //     }else{ 
    //         ans=min(ans,cost[i][j]+rec(i+1,j));
    //     }
    // }
    return ans;
}
int cal(int i){
    int ans=1e9;
    for(int j=0;j<m;j++){
        ans=min(ans,rec(i,j)+cost[i-1][j]);
    }
    return ans;
}
void solve()
{
    cin>>n>>m>>d;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)cin>>cost[i][j];
    int ans=1e9;
    for(int j=0;j<m;j++){
        ans=min(ans,rec(0,j));
    }
    cout<<ans<<endl;

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