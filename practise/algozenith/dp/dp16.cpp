#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e18+7;
map<pair<int,int>,int>mp;
int m,k;
string s;
int dp[101][101][27];
int rec(int i, int left,int prev){
    if(left<0)return -1e18;
    if(i>=s.size()){
        if(left>=0)return 0;
        return -1e18;
    }
    if(dp[i][left][prev]!=-1)return dp[i][left][prev];
    int ans=-1e18;
    for(int j=0;j<26;j++){
        if(i){
            ans=max(ans,mp[{prev,j}]+rec(i+1,left-((s[i]-'a')!=j),j));
        }else{
            ans=max(ans,rec(i+1,left-((s[i]-'a')!=j),j));
        }
    }
    return dp[i][left][prev]=ans;
}
void solve()
{
    cin>>s>>k;
    cin>>m;
    mp.clear();
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<m;i++){
        char x,y;
        int c;
        cin>>x>>y>>c;
        mp[make_pair(x-'a',y-'a')]=c;
    }
    cout<<rec(0,k,s[0]-'0')<<endl;
}
signed main()
{
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}