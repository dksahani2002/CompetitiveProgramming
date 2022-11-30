#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,k;

vector<int>v;
int rec(int i, int buy,int left){
    if(i>=n){
        if(left>=0)return 0;
        return -1e9;
    }
    if(buy){
        return max(-v[i]+rec(i+1,!buy,left), rec(i+1,buy,left));
    }
    return max(v[i]+rec(i+1,!buy,left-1),rec(i+1,buy,left));
}
void solve()
{
    cin>>n>>k;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<rec(0,1,k)<<endl;

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