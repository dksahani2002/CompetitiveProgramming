#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    string s;cin>>s;
    map<char,int>mp;
    for(auto ch:s)mp[ch]++;
    int cnt=0;
    for(auto x:mp)cnt+=(x.second%2);
    if(cnt>1){
        cout<<-1<<endl;
        return;
    }
    int l=0,r=s.size()-1,ans=0;
    while(l<r){
        int j=r;
        while(s[l]!=s[j])j--;
        if(j==l){
            swap(s[j],s[j+1]);
            ans++;
            continue;
        }else{
            while(j<r){
                swap(s[j],s[j+1]);
                j++;
                ans++;
            }
        }
        l++;
        r--;
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