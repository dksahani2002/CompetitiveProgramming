#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve()
{
    int n;cin>>n;
    vector<int>v(n+1),ans;
    int xorr=0;
    for(int i=0;i<=n;i++){
        cin>>v[i];
        xorr^=v[i];
        
    }
       
    for(int i=0;i<=n;i++)
    {  ans.push_back(xorr^v[i]) ; 
        
    }
    sort(ans.begin(),ans.end());
    for(int i=1;i<=n;i++)
    {   cout<<ans[i]<<" ";
        
    }
    cout<<endl;
      
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