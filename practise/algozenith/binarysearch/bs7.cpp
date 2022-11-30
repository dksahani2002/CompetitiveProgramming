#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,k;
vector<int>v;
bool check(int mid){
    int val=-1e9;
    int i=0;
    int count=0;
    for(int j=0;j<n;j++){
        if(v[j]==0){
            count++;
        }
        while(count>k && i<=j){
            if(v[i]==0)count--;
            i++;
        }
        val=max(val,j-i+1);
    }
    return val>=mid;
}
void solve()
{
    cin>>n>>k;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int ans=0;
    int l=0,r=1e9;
    while(l<=r){
        int mid=(l+r)/2;
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