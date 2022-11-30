#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int dp[100001][4];
string str;
vector<int>v;
int n;
int rec(int i, int s){
    if(i==n)return 0;
    if(dp[i][s]!=-1)return dp[i][s];
    int ans=1e18;
    if(s==0 && str[i]=='h'){ 
        return dp[i][s]= min(rec(i+1,1),v[i]+rec(i+1,0));
    }else if(s==1 && str[i]=='a'){ 
        return dp[i][s]= min(rec(i+1,2),v[i]+rec(i+1,1));

    }else if(s==2 && str[i]=='r'){ 
        return dp[i][s]= min(rec(i+1,3),v[i]+rec(i+1,2));
    }else if(s==3 && str[i]=='d' ){ 
        return dp[i][s]= v[i]+rec(i+1,3);
    }else{ 
        return dp[i][s]= rec(i+1,s);
    }
    // return dp[i][s]= ans;
}
void solve()
{
    cin>>n;
    cin>>str;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    memset(dp,-1,sizeof(dp));
    int ans=rec(0,0);
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