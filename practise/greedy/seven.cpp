#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
int rec(int l , int r,int lach){
    //base case
     if(l>r)return 0;
     
     //transition
     int ans = (lach+1)*(lach+1)+rec(l+1,r,0);
     for(int i=l+1;i<=r;i++){
        if(s[l]==s[i]) ans=max(ans,rec(l+1,i-1,0)+rec(i+1,r,lach+1));
     }

     //return 
     return ans;
}
void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    // vector<int>v(n);
    // for(int i=0;i<n;i++)cin>>v[i];
    cout<<rec(0,n-1,0)<<endl;
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