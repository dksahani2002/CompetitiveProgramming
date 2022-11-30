#include<bits/stdc++.h>
using namespace std;
int n;
double p[3000];
long double dp[3000][3000];
long double rec(int i , int nhd){
    if(i==n){
        if(nhd==0)return 1;
        else{
            return 0;
        }
    }
     
    if(dp[i][nhd]!=0){
        return dp[i][nhd];
    }
    long double ans=0;
    ans=rec(i+1 , nhd)*(1-p[i]) + rec(i+1 , nhd-1)*p[i];
    return dp[i][nhd]=ans;
}
int main(){
    cin>>n;
    //p.resize(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<3000;i++){
        for(int j=0;j<3000;j++){
            dp[i][j]=0;
        }
    }
    long double pi=0;
    for(int i=(n+1)/2;i<=n;i++){
        pi+=rec(0,i);
    }
    cout<<setprecision(15)<<pi<<endl;
}