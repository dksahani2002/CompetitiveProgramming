#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        cin>>v[i];
        pq.push(v[i]);
    }  
    int cost=0;
    while(!pq.empty()){
        int x=pq.top();pq.pop();
        if(pq.empty())break;
        int y=pq.top();pq.pop();
        cost+=(x+y);
        pq.push(x+y);
    }
    cout<<cost<<endl;
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