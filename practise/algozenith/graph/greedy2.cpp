#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
bool cmp(vector<int>&a, vector<int>&b){
    return a[0]*b[0]+a[1]*b[1]>a[0]*b[1]+a[1]*b[0];
}
void solve()
{
    int n;cin>>n;
    // vector<int>v1(n),v2(n);
    // int v[n][2];
    vector<vector<int>>v(n,vector<int>(2));
    for(int i=0;i<n;i++)cin>>v[i][0];
    for(int i=0;i<n;i++)cin>>v[i][1];
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++){
        cout<<v[i][0]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i][1]<<" ";
    }
    cout<<endl;
    int ans=0;
    for(int i=0;i<n;i++)ans+=v[i][0]*v[i][1];
    cout<<ans<<endl;
}
signed main()
{
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}