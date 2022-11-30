#include<bits/stdc++.h> 
using namespace std;    
#define int long long   
int mod=1e9+7;
int n;
int m,d;
string a,b;
int dp[2002][2][2][2001];
int rec(int lvl, int lti, int rti, int rem){
    if(lvl==n)return rem==0;
    
    if(dp[lvl][lti][rti][rem]!=-1){
        return dp[lvl][lti][rti][rem];
    }
    int lo=0;
    if(lti){
        lo=a[lvl]-'0';
    }
    int hi=9;
    if(rti){
        hi=b[lvl]-'0';
    }
    int ans=0;
    for(int i=lo;i<=hi;i++){
        int lt=lti,rt=rti;
        if(i!=a[lvl]-'0')lt=0;
        if(i!=b[lvl]-'0')rt=0;
        if(lvl%2){
            if(i==d)(ans+=rec(lvl+1,lt,rt,(rem*10+i)%m))%=mod;
        }
        else{
            if(i!=d)(ans+=rec(lvl+1,lt,rt,(rem*10+i)%m))%=mod;
        }
    }
    return dp[lvl][lti][rti][rem]=ans;
}

void solve(){
    memset(dp,-1,sizeof(dp));
    cin>>m>>d;
    cin>>a>>b;
    n=a.size();
    cout<<rec(0,1,1,0)<<endl;
}

signed main() { 
    int t=1;
    cin>>t;
    while(t--){
        solve();
    } 
    return 0;
}