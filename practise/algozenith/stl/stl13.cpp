#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    deque<int>dq;
    for(int i=0;i<n;i++){
        while(!dq.empty() && v[dq.back()]<v[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1)cout<<v[dq.front()]<<" ";
        if((i-dq.front()+1)==k){
            dq.pop_front();
        }
    }
    cout<<endl;
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