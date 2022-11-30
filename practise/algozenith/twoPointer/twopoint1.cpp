#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,k;cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    map<int,int>st;
    int ans=0;
    int i=0;
    for(int j=0;j<n;j++){
         st[v[j]]++;
         while(st.size()>k){
            if(st[v[i]]==1)st.erase(v[i]);
            else st[v[i]]--;
            i++;
         }
         ans+=(j-i+1);
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