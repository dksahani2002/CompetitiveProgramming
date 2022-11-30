#include <bits/stdc++.h>
using namespace std;
#define int long long
int rec(int i,int left,vector<int>&v){
    if(left<0)return -1e9;
    if(i>=v.size()){
        if(left==0){
            return 0;
        }
         return -1e9;
    }
    int ans=0;
    if(left&1){
        ans=v[i]+max(rec(i+1,left,v),rec(i+1,left-1,v));
    }else{
        ans=-v[i]+max(rec(i+1,left,v),rec(i+1,left-1,v)); 

    }
    return ans;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int val=rec(0,k,v);
    cout<<val<<endl;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}