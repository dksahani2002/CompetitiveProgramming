#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,q;
vector<int>v;
 
void BS(int x){
    int l=0,r=n-1;
    int peak=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(v[mid]>v[mid-1]){
            peak=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    l=0,r=peak;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(v[mid]==x){
            ans=mid;
        }
        if(v[mid]>x){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    if(ans!=-1){
        cout<<ans+1<<" ";
    }
    l=peak+1;
    r=n-1;
    ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(v[mid]==x){
            ans=mid;
        }
        if(v[mid]>x){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    if(ans!=-1){
        cout<<ans+1<<" ";
    }
    cout<<endl;
}
void solve()
{
    cin>>n>>q;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    while(q--){
        int x;cin>>x;
        BS(x);
    }
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