#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i)v[i]=max(v[i],v[i-1]);
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(v[i]==i+1)cnt++;
    }
    cout<<cnt<<endl;

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