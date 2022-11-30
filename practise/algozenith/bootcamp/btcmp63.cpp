#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;
    cin>>s;
    int mask=0,ans=0;
    int n=s.size();
    vector<int>m(1<<10,n+1);
    m[0]=-1;
    for(int i=0;i<n;i++){
        mask^=(1<<(s[i]-'0'));
        for(int j=0;j<10;j++){
            ans=max(ans,i-m[mask^(1<<j)]);
        }
        ans=max(ans,i-m[mask]);
        m[mask]=min(m[mask],i);
    }
    cout<<ans<<endl;
}

signed main()
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;
    cin >> _t;
    while (_t--)
        solve();
}