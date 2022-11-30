#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
    int n,s,m;
    vector<int>v;
bool check(int val){
    int sum=0;
    for(int i=0;i<n;i++){
        int change=max(0LL,val-v[i]);
        if(sum+change<=(s*m) && change<=m){
            sum+=change;
        }else{
            return false;
        }
    }
    return true;
}
void solve()
{
    cin>>n>>s>>m;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    int ans=*min_element(v.begin(),v.end());
    int l=0,r=1e18;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
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