#include <bits/stdc++.h>
using namespace std;
#define int long long

void rec(int i , int n , int k , vector<int>&v , int damage,int &ans , int ki){
    if(i>n)return;
    if(i==n){
        if(k>0){
             ans=min(ans,damage + ki*(Ki+1)/2);
        } 
    }
    rec(l+1,n,k,v,damage+v[i]);
    for(int l=i+2;l<i+k;l++){
        rec(l,n,k-1,v,damage,ans,ki);
    }
}
void solve()
{ 
    int n,k;cin>>n>>k;
    int ki=k;
    vector<int>v(n);
    vector<int>ans;
    for(int i=0;i<n;i++)cin>>v[i];
    int damage=0;
    int ans=1e9;
    rec(0,n,k,v,damage,ans,ki);
    cout<<ans<<endl;
    return;
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