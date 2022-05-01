#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[101];
int dp[100100];
int rec(int k){
    if(k==0){
        return 1;
    }
    if(dp[k]!=-1){
        return dp[k];
    }
    int ans=1;
    for(int i=0;i<n;i++){
        if(k>=a[i] && rec(k-a[i])){
            ans= 0; 
        }
    }
    return dp[k]= ans;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    if(rec(k)){
        cout<<"SECOND"<<endl;
    }
    else{
        cout<<"FIRST"<<endl;
    }
    
    return 0;
}