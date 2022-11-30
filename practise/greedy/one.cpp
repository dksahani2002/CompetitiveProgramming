#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
bool cmp(pair<int,int>&a,pair<int,int>&b){
    return a.second<b.second;
}
int maxinterval(vector<pair<int,int>>&v){
    int cnt=1;
    int prev=v[0].second;
    for(int i=1;i<v.size();i++){
        if(v[i].first>prev){
            cnt++;
            prev=v[i].second;
        }
    }
    return cnt;
}
void solve()
{
    int n;cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++)cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end(),cmp);
    cout<<maxinterval(v)<<endl;
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