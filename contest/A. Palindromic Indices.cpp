#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
    int n;cin>>n;
    string s;
    cin>>s;
    int mid=s[n/2];
    int l=n/2-1;
    int r=n/2+1;
    int ans=0;
     while(s[l]==mid && l>=0){
         ans++;
         l--;
     }
     while(s[r]==mid && r<n){
         ans++;
         r++;
     }
     cout<<ans+1<<endl;
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