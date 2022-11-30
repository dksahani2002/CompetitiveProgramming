#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    string s;cin>>s;
    int ans=0;
    int i=0,j=0;
    set<char>vow;
    vow.insert('a');
    vow.insert('e');
    vow.insert('i');
    vow.insert('o');
    vow.insert('u');
    map<char,int>mp;
    for(;j<=s.size();j++){
        if(vow.count(s[j])==0 || j==s.size()){
            while(i<s.size() && i<=j){
                if(mp[s[i]]==1)mp.erase(s[i]);
                else mp[s[i]]--;
                if(mp.size()==5)ans++;
                i++;
            }
            mp.clear();
            continue;
        }
        mp[s[j]]++;
        if(mp.size()==5)ans++;
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