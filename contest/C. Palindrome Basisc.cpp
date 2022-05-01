#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
vector<int>v;
int dp[40004][505];
int rec(int i ,int n){
    if(n==0)return 1;
    if(i==v.size() ){
        if(n==0)return 1;
        else return 0;
    }
    if(dp[n][i]!=-1)return dp[n][i];
    int ans=0;
    ans+=rec(i+1,n);
    ans%=mod;
    if(n>=v[i]){
        ans+=rec(i,n-v[i]);
        ans%=mod;
    }
    return  dp[n][i]=ans; 
}
signed main(){
    int t;cin>>t;
    for(int i=1;i<=40004;i++){
       string a = to_string(i);
       string b=a;
       reverse(b.begin(),b.end());
       if(a==b)v.push_back(i);
    }
    memset(dp,-1,sizeof(dp)); 
 
    // int x=v.size();
    while(t--){
        int n;
        cin>>n;
        cout<<rec(0,n)<<endl;
    }
}