// https://atcoder.jp/contests/dp/tasks/dp_d
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,W;
int wt[101];
int val[101];
int dp[101][100001];
int rec(int lev , int w){
    if(lev==n){
        return 0;
        
    }
    if(dp[lev][w]!=-1){
        return dp[lev][w];
    }
    int ans=rec(lev+1 ,w);
    if(w+wt[lev]<=W)ans=max(rec(lev+1 , w+wt[lev])+val[lev] , ans );
    return dp[lev][w]=ans;
}
signed main(){
    cin>>n>>W;
    for(int i=0;i<n;i++){
        cin>>wt[i]>>val[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
    return 0;
}