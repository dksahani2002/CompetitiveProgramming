#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
void solve()
{
    cin>>n>>k;
    string s;
    cin>>s;
    int last[26];
    for(int i=0;i<26;i++)last[i]=-1;
    int dp[n+1],sum[n+1];
    dp[0]=1;
    sum[0]=1;
    map<int,int>mp[n+1];
    mp[0][0]=1;
    for(int i=1;i<=n;i++){
        int id=s[i]-'a';
        for(int j=0;j<i;j++){
            mp[i][j]=1+mp[i-1][j];
            if(last[id]>0){
                mp[i][j]-=mp[id-1][j];
            }
        }
        mp[i][i]=1;
        last[id]=i;
    }
    int cnt=k;
    int cost=0;
    for(int i=n;i>=0;i--){
        for(auto x:mp[i]){
            if(x.second>=cnt){
                cost+=(n-x.first)*cnt;
                cnt=0;
                cout<<cost<<endl;
                return;
            }else{
                cost+=(n-x.first)*x.second;
                cnt-=x.second;
            }
        }
    }
  
        cout<<-1<<endl;
     
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