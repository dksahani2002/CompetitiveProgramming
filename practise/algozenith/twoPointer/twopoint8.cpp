#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    map<char,int>mp1;
    for(auto ch:s)mp1[ch]++;
    int i=0;
    int ans=0;
    for(auto ch='a'; ch<='z';ch++){
        map<char,int>mp;
        int tail=0,head=0;
        while(tail<n){
            if(head<n && s[head]==ch){
                mp[ch]++;
            }
            if(mp.size()>0 && s[tail]==ch){
                ans+=head-tail+1;
            }
            if(head<n)head++;
            if(head==n)tail++;
        }
    }
    for(auto e:mp1){
        ans-=e.second-1;
    }
    
    cout<<ans<<endl;

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