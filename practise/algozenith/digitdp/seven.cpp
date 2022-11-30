#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// #define int long long
const int mod=1e9+7;
string r;

vector<bool>prime;
bool isprime(int n){
    if(n<2){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int dp[51][2][2][451][451][2];
int rec(int lev, int rt1,int rt2, int sumx, int sumy, bool xgy){
    if(lev>=r.size()){
        if(xgy==0 && isprime(sumx+sumy) && sumx<sumy)return 1;
        return 0;
    }
    if(dp[lev][rt1][rt2][sumx][sumy][xgy]!=-1)return dp[lev][rt1][rt2][sumx][sumy][xgy];
    int hi1=9,hi2=9;
    long long ans=0;
    if(rt1)hi1=r[lev]-'0';
    if(rt2)hi2=r[lev]-'0';
    for(int i=0;i<=hi1;i++){
        int nrt1=rt1;
        if(i!=r[lev]-'0')nrt1=0;
        for(int j=0;j<=hi2;j++){
            int nrt2=rt2;
            if(j!=r[lev]-'0')nrt2=0;
            int nxgy=xgy;
            if(xgy && j<i)continue;
            if(xgy && j>i)nxgy=0; 
            ans+=rec(lev+1,nrt1,nrt2,sumx+i,sumy+j,nxgy);
            ans%=mod;
        }
    }
    return dp[lev][rt1][rt2][sumx][sumy][xgy]=ans%mod;
}
void init(){
    prime.resize(1001,0);
    for(int i=2;i<=1000;i++){
        bool check=true;
        for(int j=2;j*j<=i;j++){
            if(i%j==0)check=false;
        }
        if(check)prime[i]=1;
        
    } 
}
void solve()
{
    cin>>r;
    memset(dp,-1,sizeof(dp));
    int ans=rec(0,1,1,0,0,1);
    cout<<ans<<endl;
}
int main()
{
    fast;
    // init();
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
