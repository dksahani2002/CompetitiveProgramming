 #include <bits/stdc++.h>
using namespace std;
#define int long long
map<pair<int,int>,int>mp;
int dp[101][101][26];
string s;
int k,m;
int rec(int i,int ch,int prev){
    if(ch>k)return -1e18;
    if(i>=s.size()){
        if(ch<=k)return 0;
        return -1e18;
    }
    if(dp[i][ch][prev]!=-1)return dp[i][ch][prev];
    int ans=-1e18;
    int cur=s[i]-'a';
    for(int j=0;j<26;j++){
        if(i){
            ans=max(ans,mp[{prev,j}]+rec(i+1,ch+(cur!=(j)),j));
        }else{
            ans=max(ans,rec(i+1,ch+(cur!=(j)),j));
        } 
    }
    return dp[i][ch][prev]= ans;
}
void solve()
{
    cin>>s>>k;
    cin>>m;

    for(int i=0;i<m;i++){
        char x,y;
        int w;cin>>x>>y>>w;
        mp[{x-'a',y-'a'}]=w;
    }
    memset(dp,-1,sizeof(dp));
    int ans=rec(0,0,s[0]-'a');
    cout<<ans<<endl;
    mp.clear();
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