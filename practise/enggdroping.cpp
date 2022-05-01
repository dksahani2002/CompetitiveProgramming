#include<bits/stdc++.h>
using namespace std;
int k,n,t=0,ans;
int dp[1001][1001];
int rec(int fl , int egg){
    if(fl==n-1){
        if(egg==0){
            if(t==0){
                ans=dp[fl][egg];
                t=1;
            }
            return 1;
            
        }
        else{
            return 0;
        }
    }
    if(dp[fl][egg]!=-1){
        return dp[fl][egg];
    }
 
    return dp[fl][egg]= max(rec(fl+1 , egg) ,rec(fl+1 , egg), rec(fl+1 , egg-1));
}
int main(){
    cin>>k>>n;
    ans=0;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,k)<<" "<<ans<<endl;
    return 0;
}