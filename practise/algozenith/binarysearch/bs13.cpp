#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,k;
vector<int>v;
bool check(int mid){
    int req=1;
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum+v[i]>mid){
            req++;
            sum=v[i];
        }else{
            sum+=v[i];
        }
    }
    return req<=k;
}
void solve()
{
    cin>>n>>k;
    v.clear();
    v.resize(n);
    int r=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        r+=v[i];
    }
    // r=1e9;
    int l=*max_element(v.begin(),v.end()),ans=0;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
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