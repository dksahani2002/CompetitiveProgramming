#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,k;
vector<int>v;
bool check(int mid){
    int req=1;
    int last=v[0];
    for(int i=1;i<n;i++){
        if( v[i]>=mid+last){
            last=v[i];
            req++;
        } 
    }
    return req>=k;
}
void solve()
{
    cin>>n>>k;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int ans=0;
    int l=1,r=v[n-1]-v[0];
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            // r=mid-1;
            l=mid+1;
        }else{
            // l=mid+1;
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