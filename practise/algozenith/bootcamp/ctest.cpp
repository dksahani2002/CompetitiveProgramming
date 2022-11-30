#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
 map<int,int>mp;
 void primes(int n){
    int m=n;
    while(n%2==0){
        if(m==n)mp[2]++;
        n/=2;
    }
    for(int i=3;i*i<=n;i+=2){
        m=n;
        while(n%i==0){
            if(m==n)mp[i]++;
            n/=i;
        }
    }
    if(n>2)mp[n]++;
 }
void solve()
{

   int n,m;cin>>n>>m;
   vector<int>v1(n),v2(m);
   for(int i=0;i<n;i++)cin>>v1[i];//vbinaru
   for(int i=0;i<m;i++)cin>>v2[i];
   for(auto e:v2){
         primes(e);
   }
    for(auto i:mp){
        if(i.second%2){
            for(int j=i.first-1;j<n;j+=i.first){
                v1[j]=1-v1[j];
            }
        }
    }
    for(auto e:v1){
        cout<<e<<" ";
    }
    cout<<endl;
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