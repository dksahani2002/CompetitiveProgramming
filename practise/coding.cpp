#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int arr[201][201];
int dp[201][201][401];
const int mod =1e9+7;
#define int long long 
int rec(int i , int j , int klft){
    if(i<0 || j<0 || klft<0){
        return 0;
    }
    if(i==0 && j==0){
        if(arr[i][j]==1){
            if(klft>0){
                return 1;
            }
            else{
                return 0;
            }
        }else{
            return 1;
        }
    }
    if(dp[i][j][klft]!=-1){
        return dp[i][j][klft];
    }
    if(arr[i][j]==1){
        if(klft>0){
            arr[i][j]=0;
            int ans= (rec(i-1,j,klft-1)%mod + rec(i,j-1,klft-1)%mod)%mod;
            arr[i][j]=1;
            return dp[i][j][klft]=ans;
        }else{
            int ans=0;
            return dp[i][j][klft]=ans;
        }
    }else{
        int ans=(rec(i-1,j,klft)%mod + rec(i,j-1,klft)%mod)%mod;
        return dp[i][j][klft]=ans;
    }
}
signed main(){
    int t;
    cin>>t;
   
    while(t--){
          cin>>n>>m>>k;
          for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                  cin>>arr[i][j];
              }
          }
          memset(dp,-1,sizeof(dp));
          if(arr[n-1][m-1]==1){
              if(k>0){
                  arr[0][0]=0;
                  k--;
                  cout<<rec(n-1,m-1,k)<<endl;
              }
              else{
                  cout<<0<<endl;
              }
          }else{
              cout<<rec(n-1,m-1,k)<<endl;
          }
          
    }
    return 0;
}