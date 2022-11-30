#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n;
string s;
vector<int>v;
int dp[100100][4];
int rec(int i, int state){
    if(i>=n)return 0;
    if(dp[i][state]!=-1)return dp[i][state];
    int ans=1e9;
    if(state==0){
        if(s[i]=='h'){
            ans=min(rec(i+1,1), v[i]+rec(i+1,0));
        }else{
            ans=rec(i+1,state);
        }
    }else if(state==1){
        if(s[i]=='a'){
            ans=min(rec(i+1,2), v[i]+rec(i+1,1));
        }else{
            ans=rec(i+1,state);
        }
    }else if(state==2){
        if(s[i]=='r'){
            ans=min(rec(i+1,3), v[i]+rec(i+1,2));
        }else{
            ans=rec(i+1,state);
        }
    }else if(state==3){
        if(s[i]=='d'){
            ans= v[i]+rec(i+1,3);
        }else{
            ans=rec(i+1,state);
        } 
    }
    return  dp[i][state]=ans;
}
void solve()
{
    cin>>n;
    cin>>s;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<=n;i++){
        for(int j=0;j<4;j++)dp[i][j]=-1;
    }
    cout<<rec(0,0)<<endl;
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