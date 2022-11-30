#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,k;
    cin>>n>>k;
    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        pq.push(x);
    }
    int ans=0;
    while(!pq.empty() && k--){
        int temp=pq.top();pq.pop();
        ans+=temp;
        temp/=2;
        if(temp)pq.push(temp);
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