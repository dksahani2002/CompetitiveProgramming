#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
// struct data{
//     int A;
//     int B;
//     int C;
// };
int rew[100100][3]; 
// data Dt[100100];
int dp[100100][3];
int rec(int i , int prev){
    if(i==n){
        return 0;
    }
    if(dp[i][prev]!=-1){
        return dp[i][prev];
    }
    int ans=0;
    for(int j=0;j<3;j++){
        if(j!=prev)ans=max(ans,rec(i+1 , j) + rew[i][j]);
    }
    return dp[i][prev]=ans;
    // if(i>=n){
    //     return 0;
    // }
    
    // // if(dp[i]!=-1){
    // //     return dp[i];
    // // }
    // int ans=ch;
    // if(ch==Dt[i].A){
    //     ans+=max(rec(i+1 ,Dt[i+1].B)  , rec(i+1 ,Dt[i+1].C) );
    // }
    // if(ch==Dt[i].B){
    //     ans+=max(rec(i+1 ,Dt[i+1].A) , rec(i+1 ,Dt[i+1].C) );
    // }
    // if(ch==Dt[i].C){
    //     ans+=max(rec(i+1 ,Dt[i+1].B) , rec(i+1 ,Dt[i+1].A) );
    // }
    // return  ans;
}
signed main() {
	cin>>n;
	int mx;
	for(int i=0;i<n;i++){
	    // int a,b,c;
	    cin>>rew[i][0]>>rew[i][1]>>rew[i][2]; 
	    // Dt[i].A=a;
	    // Dt[i].B=b;
	    // Dt[i].C=c;
	}
	memset(dp,-1,sizeof(dp));
    cout<<max({rec(0,0),rec(0, 1),rec(0, 2)})<<endl;  
	return 0;
}