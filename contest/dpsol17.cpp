#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<int>fq;
int fact[5001],ifact[5001];
int expo(int a, int b ){
    a%=mod;
    int ans=1;
    while(b){
        if(b&1)(ans*=a)%=mod;
        (a*=a)%=mod;
        b >>=1;
    }
    return ans;
}
void pre(){
    fact[0]=1;
    fact[1]=1;
    ifact[0]=expo(fact[0],mod-2);
    ifact[1]=expo(fact[1],mod-2);
    for(int i=2;i<5001;i++){
        (fact[i]=i*fact[i-1])%=mod;
        ifact[i]=expo(fact[i],mod-2);
    }
}
int dp[27][5010];
int rec(int i, int cnt){
    if(i==26){
        if(cnt==0)return 0;
        return fact[cnt];
    }
    auto &ans=dp[i][cnt];
    if(ans!=-1)return ans;
    ans=0;
    for(int j=0;j<=fq[i];j++){
        (ans+=rec(i+1,cnt+j)*ifact[j])%=mod;
    }
    return ans;
}
void solve()
{   pre();
    string s;
    cin>>s;
    fq.clear();
    fq.assign(26,0);
    memset(dp,-1,sizeof(dp));
    for(auto &c:s)fq[c-'a']++;
    cout<<rec(0,0)<<endl;
}
signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}