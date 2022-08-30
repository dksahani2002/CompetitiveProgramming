#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n,k;cin>>n>>k;
    vector<int>v(n+1,0);
    for(int i=1;i<=n;i++)cin>>v[i];
    int j=0,r=0; 
    int ans=0;
    for(int i=1; i<=n;i++){ 
         v[i]+=v[i-1]; 
    }
    if(k>n){ 
        // cout<<"v[n]: "<<v[n]<<endl;
        cout<<v[n] + n*k - (n*(n+1))/2 <<endl;
        return;
    } 
    for(int i=k;i<=n;i++){
        ans=max(ans,v[i]-v[i-k]); 
    }
    cout<<ans+(k*(k-1))/2<<endl;
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
