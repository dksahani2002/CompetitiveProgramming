#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,k,d;
    cin>>n>>k>>d;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    map<int,int>mp;
    int res=-1e9,sum=0;
    int i=0;
    for(int j=0;j<n;){
        sum+=v[i];
        if(v[i]%2)mp[v[i]]++;
        while(j<=i && (mp.size()>k || sum>d)){
            sum-=v[j];
            if(mp[v[j]]==1){
                mp.erase(v[j]);
            }
            if(mp.count(v[j])>1)mp[v[j]]--;
            j++;
        }
        i++;
       res=max(res,sum);
    }
    cout<<res<<endl;
}
signed main()
{
    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}