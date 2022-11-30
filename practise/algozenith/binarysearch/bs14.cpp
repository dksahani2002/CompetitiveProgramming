#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m,k;
vector<int>v1,v2;
bool check(int mid){
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=upper_bound(v2.begin(),v2.end(),mid-v1[i])-v2.begin();
    }
    return cnt>=k;
}
void solve()
{
    cin>>n>>m>>k;
    v1.clear();
    v1.resize(n);
    v2.clear();
    v2.resize(m);
    for(int i=0;i<n;i++)cin>>v1[i];
    for(int i=0;i<m;i++)cin>>v2[i];
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if(n>m){
        swap(v1,v2);
        swap(n,m);        
    }
    int l=v1[0]+v2[0];
    int r=v1[n-1]+v2[m-1];
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
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