 #include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    map<int,int>mp;
    for(int i=0;i<n;i++)cin>>v[i],mp[v[i]]++;
    int ans=1e9;
    int k=mp.size();
    mp.clear();
    int i=0;
    for(int j=0;j<n;j++){
        mp[v[j]]++;
       while(i<=j && (int)mp.size()==k){
         ans=min(ans,(j-i+1));
         if(mp[v[i]]==1)mp.erase(v[i]);
         else mp[v[i]]--;
         i++;
       }
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