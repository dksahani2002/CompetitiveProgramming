#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,k;
vector<int>v;
bool check(int val){
    int sum=0;
    for(int i=0;i<v.size();i++){
        int change=min(val,v[i]);
        sum+=change;
    }
    return sum>=val*k;
}
void solve()
{
    cin>>n>>k;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        mp[x]++;
    }
    v.clear();
    for(auto x:mp){
        v.push_back(x.second);
    }
    int l=0,r=1e9;
    int ans=0;
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