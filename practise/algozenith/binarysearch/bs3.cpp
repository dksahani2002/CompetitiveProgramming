#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
    int n,s,m;
    vector<int>v;
bool check(int val){
    vector<int>a=v,buffer(n);
    int sum=0;
    for(int i=0;i<n;i++){
        if(i)buffer[i]+=buffer[i-1];
        a[i]+=buffer[i];
        if(a[i]>=val)continue;
        int change=val-a[i];
        if(change>m)return false;
        sum+=change;
        buffer[i]+=change;
        if(i+s<n)buffer[i+s]-=change;
    }

    return sum<=m;
}
void solve()
{
    cin>>n>>s>>m;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
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