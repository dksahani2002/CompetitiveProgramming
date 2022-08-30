#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;cin>>n;
    map<int,int>mp;
    for(int i=1;i<=n/2;i++){
        int gc=__gcd( n-i ,i);
        int x=gc+(i*(n-i))/gc;
        mp[x]++;
       if(i!=(n-i)) mp[x]++;
    }
   for(auto i:mp){
    cout<<i.second<<endl;
    return;
   }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}