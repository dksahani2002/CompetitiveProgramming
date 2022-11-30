#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<int>primes;
int n,k;
vector<int>v;
 vector<bool>prime;
void init(){
    prime.clear();
   prime.assign(10000,true);
    for(int i=2;i*i<10000;i++){
        if(prime[i]){
            for(int j=i*i;j<=10000;j+=i){
                prime[j]=0;
            }
        }
    }
    for(int i=0;i<=10000;i++){
        if(prime[i])primes.push_back(i);
    }
}
int rec(int i, int r, int term,int first){
    if(i>=n){
        if(term==k)return 1;
        return 0;
    }
    if(first==-1 || v[i]==(pow(term,r)*v[first])){
        return rec(i+1,r,term+1,i)+rec(i+1,r,term,first);
    }else{
        return rec(i+1,r,1,i)+rec(i+1,r,term,first);
    }
}
void solve()
{
    init();
    cin>>n>>k;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int ans=0;
    // for(auto e:primes){
    //     ans+=rec(0,e,0,-1);
    // }
    vector<map<int,int>>mp;
    for(auto r:primes){
        for(int i=0;i<i;i++){
            if(v[i]%v[j]==0){
                int r=v[i]/v[j];
                int cnt=0;
                if(mp[j].find(v[i]/v[j])!=mp[j].end()){
                    cnt+=mp[j][v[i]/v[j]];
                }
                ans+=mp[j][v[i]/v[j]];
                mp[j][v[i]/v[j]]+=cnt+1;
            }
        }
    }
    cout<<ans<<endl;
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