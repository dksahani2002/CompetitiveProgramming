#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
string l,r;
int n;
int dp[20][2][2][2][2][11][11][2];
int rec(int lev, int lt, int rt, int od, int ev, int sec_last, int last, int zero){
    if(lev==n){
        if(od==1 && ev==1)return 1;
        return 0;
    }
    if(dp[lev][lt][rt][od][ev][sec_last][last][zero]!=-1)return dp[lev][lt][rt][od][ev][sec_last][last][zero];
    int low=0,hi=9,ans=0;
    if(lt)low=l[lev]-'0';
    if(rt)hi=r[lev]-'0';
    for(int i=low;i<=hi;i++){
        int nlt=lt,nrt=rt;
        if(i!=l[lev]-'0')nlt=0;
        if(i!=r[lev]-'0')nrt=0;
        if(zero==0){
            if(i==0)ans+=rec(lev+1,nlt,nrt,od,ev,sec_last,last,zero);
            else ans+=rec(lev+1,nlt,nrt,od,ev,sec_last,i,1-zero);
        }else{
            int nod=od,nev=ev;
            if(i==last)nev=1;
            if(i==sec_last)nod=1;
            ans+=rec(lev+1,nlt,nrt,nod,nev,last,i,zero);
        }
    }
    return dp[lev][lt][rt][od][ev][sec_last][last][zero]=ans;
}
void solve()
{
    cin>>l>>r;
    int L=stoll(l);
    int R=stoll(r);
    L++;
    if(L>R){
        cout<<0<<endl;
        return;
    }
    l=to_string(L);
    r=to_string(R);
    l=string(r.size()-l.size(),'0')+l;
    n=r.size();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,1,1,0,0,10,10,0)<<endl;
}
signed main()
{
    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}