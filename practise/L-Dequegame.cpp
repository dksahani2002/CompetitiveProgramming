#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[3001];
int dp[3001][3001][2];
int n;
int rec(int l , int r,int p){
    //if(l==r)return ar[l];
    if(l>r)return 0;
    if(dp[l][r][p]!=-1){
        return dp[l][r][p];
    }
    if(p)return dp[l][r][p]=max(rec(l+1 , r , 1-p) +arr[l] , rec(l , r-1 , 1-p)+arr[r]);
    else return dp[l][r][p]=min(rec(l+1 , r , 1-p)   , rec(l , r-1 , 1-p) );
      
}
signed main(){
    cin>>n;
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    for(int i=0;i<=3000;i++){
        for(int j=0;j<=3000;j++){
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
    }
    int x=rec(0,n-1 ,1); 
    cout<<(2*1LL*x-sum)<<endl;
    return 0;
}