#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;

void solve()
{
    int n;cin>>n;
    // vector<int>prime;
    map<int,int>mp;
    int m=n;
    
    int ans=0;
    int i=2;
    while(m>1){
        if(m%i==0){
            mp[i]++;
            m/=i;
        }else{
            i++;
        }
    }
    int res=n;
    for(auto v:mp){
        // cout<<v.first<<" "<<v.second<<endl;
        n=(n*(v.first-1))/v.first;
    }
    cout<<n<<endl;
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