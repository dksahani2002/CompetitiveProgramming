#include<bits/stdc++.h>
using namespace std;

int dp[10005];
int rec(int n){
    if(n<0)
      return 0;

    if(n==0)
       return 1;

    if(dp[n] != -1)
        return dp[n];
    return dp[n] = rec(n-3)+rec(n-1);
}

void solve(){
    int n; cin>>n;
    memset(dp, -1, sizeof(dp));
    cout<<rec(n)<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
}