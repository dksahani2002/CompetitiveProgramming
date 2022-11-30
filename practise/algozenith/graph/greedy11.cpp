#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n;
vector<pair<int,int>>v;
void solve()
{
    cin>>n;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>v[i].second;
    }
    v.push_back({0,0});
    sort(v.rbegin(),v.rend());
    int ans=0;
    priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(v[0].second);
    for(int i=1;i<=n;i++){
        int chunk=v[i-1].first-v[i].first;
        while(!pq.empty() && chunk>0){
             int dur=pq.top();pq.pop();
             int sptime=min(dur,chunk);
             dur-=sptime;
             chunk-=sptime;
             if(dur>0)pq.push(dur);
             else ans++;
        }
        pq.push(v[i].second);
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