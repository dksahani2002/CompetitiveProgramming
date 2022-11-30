 #include <bits/stdc++.h>
 using namespace std;
 #define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 #define int long long
 const int mod=1e9+7;
 string toBinary(int n, int len)
 {
    string binary;
    for (unsigned i = (1 << len - 1); i > 0; i = i / 2) {
        binary += (n & i) ? "1" : "0";
    }
    return binary;
 } 
 string l,r;
 int n;
 int dp[64][2][2][2][2];
int rec(int lev, int lt1,int rt1, int lt2, int rt2){
    if(lev>=r.size())return 0;
    if(dp[lev][lt1][rt1][lt2][rt2]!=-1)return dp[lev][lt1][rt1][lt2][rt2];
    int l1=0,l2=0,r1=1,r2=1,ans=-1e9;
    if(lt1)l1=l[lev]-'0';
    if(rt1)r1=r[lev]-'0';
    if(lt2)l2=l[lev]-'0';
    if(rt2)r2=r[lev]-'0';
    for(int i=l1;i<=r1;i++){
        int nlt1=lt1,nrt1=rt1;
        if(i!=l[lev]-'0')nlt1=0;
        if(i!=r[lev]-'0')nrt1=0;
        for(int j=l2;j<=r2;j++){
            int nlt2=lt2,nrt2=rt2;
            if(j!=l[lev]-'0')nlt2=0;
            if(j!=r[lev]-'0')nrt2=0;
            ans=max(ans,(i^j)*(1LL<<(n-lev-1))+rec(lev+1,nlt1,nrt1,nlt2,nrt2));
        }
    }
    return dp[lev][lt1][rt1][lt2][rt2]=ans;
}
 void solve()
 {
    int nn,m;cin>>nn>>m;
     l= toBinary(nn, log2(m)+1);
     r= toBinary(m, log2(m)+1);
     n=r.length();
     memset(dp,-1,sizeof(dp));
    cout<<rec(0,1,1,1,1)<<endl;
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