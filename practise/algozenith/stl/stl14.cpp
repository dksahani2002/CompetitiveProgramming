#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    // vector<int>v(n);
    // int max1=1e9,max2=1e9;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        // cin>>v[i];
        int x;cin>>x;
        pq.push(x);
        // if(x<max1){
        //     max2=max1;
        //     max1=x;
        // }else if(x<max2){
        //     max2=x;
        // }
    }
    int max2=pq.top();
    while(!pq.empty() && pq.top()==max2){
        pq.pop();
    }
    if(!pq.empty()){
        max2=pq.top();
    }else max2=-1;
    cout<<max2<<endl;
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