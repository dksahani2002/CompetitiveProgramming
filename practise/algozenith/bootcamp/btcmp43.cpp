#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int i=n-2;
    for(;i>=0;i--){
        if(v[i]<v[i+1]){
            int j=n-1;
            while(j>=0 && v[j]<=v[i])j--;
            swap(v[i],v[j]);
            break;
        }
    }
    reverse(v.begin()+i+1,v.end());
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
}
signed main()
{
    fast;
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}