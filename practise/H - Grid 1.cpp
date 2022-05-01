#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n , m;
string arr[1001];
int dp[1001][1001];
int rec(int i , int j){
    if(i==n-1 && j==m-1){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    if(i+1<n && arr[i+1][j]!='#'){
        ans=rec(i+1,j)%mod;
    }
    if(j+1<m && arr[i][j+1]!='#'){
        ans+=rec(i,j+1);
    }
    return dp[i][j]=ans%mod;
}
signed main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        //cout<<arr[i]<<endl;
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
}