#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,z;
    cin>>n>>z;
    int ans=0;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
   
        for(int i=0;i<n;i++){
             
                 ans=max(ans,(z|v[i]));
                 
        }
    
    cout<<ans<<endl;
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