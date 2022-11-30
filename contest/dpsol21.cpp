#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<string>grid;
string s;
// int dp[501][501];
// map<string,int>mp;
map<pair<pair<int,int>,string>,int>dp2;
int rec(int i, int j){
    if(i>=n || j>=m)return 0;
    if(i==n-1 && j==m-1){
        s.push_back(grid[i][j]);
        int l=0,r=s.size()-1;
        while(l<r && s[l]==s[r]){
                l++;
                r--;
        }
        s.pop_back();
        return l==r;
    }
    // if(dp[i][j]!=-1)return dp[i][j];
    // string key=to_string(i)+'#'+to_string(j)+'#'+s;

    // if(mp.find(key)!=mp.end())return mp[key];
    if(dp2[{{i,j},s}])return dp2[{{i,j},s}];
    int ans=0;
    s.push_back(grid[i][j]);
    ans+=rec(i+1,j)+rec(i,j+1);
    s.pop_back();
    // return  dp[i][j]= ans;
    // return mp[key]=ans;
    return dp2[{{i,j},s}]=ans;
}
void solve()
{
    cin>>n>>m;
    grid.resize(n);
    // dp2.clear();
    for(int i=0;i<n;i++){
        cin>>grid[i];
        // cout<<grid[i]<<endl;
    }
    // memset(dp,-1,sizeof(dp));
    s="";
    cout<<rec(0,0)<<endl;
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