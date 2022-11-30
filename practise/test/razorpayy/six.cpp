#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
int minimumOperations(int n, int k, vector<int>&A){
        vector<int>v=A;
         vector<pair<int,int>>p(n);
        for(int i=0;i<n;i++){
            p[i]={v[i],i};
        }
        sort(p.rbegin(),p.rend());
        
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[p[i].first]=abs(p[i].second-i);
        }
        int cnt=0;
        for(auto e:mp){
            cnt+=(e.second>=k);
        }
        return cnt;
}
void solve()
{
    int n,k;cin>>n>>k;
    vector<int>v(n);
   for(int i=0;i<n;i++) cin>>v[i];
   cout<<minimumOperations(n, k,v)<<endl;
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