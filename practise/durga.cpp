#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
struct data{
    int A;
    int B;
    int C;
};
data Dt[100100];
int dp[100100];
int rec(int i , int ch){
    if(i>=n-1){
        return 0;
    }
    
    // if(dp[i]!=-1){
    //     return dp[i];
    // }
    int ans=0;
    if(ch==Dt[i].A){
        ans=Dt[i].A+max(rec(i+1 ,Dt[i+1].B)+Dt[i+1].B , rec(i+1 ,Dt[i+1].C)+Dt[i+1].C);
    }
    if(ch==Dt[i].B){
        ans=Dt[i].B+max(rec(i+1 ,Dt[i+1].A)+Dt[i+1].A , rec(i+1 ,Dt[i+1].C)+Dt[i+1].C);
    }
    if(ch==Dt[i].C){
        ans=Dt[i].C+max(rec(i+1 ,Dt[i+1].B)+Dt[i+1].B , rec(i+1 ,Dt[i+1].A)+Dt[i+1].A);
    }
    return dp[i]=ans;
}
signed main() {
	cin>>n>>k;
	int mx;
	for(int i=0;i<n;i++){
	    int a,b,c;
	    cin>>a>>b>>c;
	    if(i==0){
	       mx=max({a,b,c}); 
	    }
	    Dt[i].A=a;
	    Dt[i].B=b;
	    Dt[i].C=c;
	}
	 cout<<rec(0,mx)<<endl; 
//	memset(dp,-1,sizeof(dp));
 
	return 0;
}