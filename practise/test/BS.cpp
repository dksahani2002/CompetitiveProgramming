#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<int>v,q;
int n,c;
bool check(int mid){
    int val=q[mid-1];
    int len=0,sum=0;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        if(v[i]>=val)sum++;
        else sum--;
        if(sum>0){
            len=i+1;
        }
        else if(sum<=0){
            if(mp.find(sum-1)!=mp.end()){
                len=max(len,i-mp[sum-1]);
            }
        }
        if(mp.find(sum)==mp.end())mp[sum]=i;
    }
    return len>=c;
}
void solve()
{
    cin>>n>>c;
    v.clear();
    v.resize(n);
    
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    q=v;
    sort(q.rbegin(),q.rend());
    for(auto e:q)cout<<e;
    cout<<endl;
    int l=1,r=n;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
}