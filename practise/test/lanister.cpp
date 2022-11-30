#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    string s;
    cin>>s;
    map<char,char>mp;
    int i=0;
    for(int j=0;j<s.size();j++){
        if(mp.count(s[j])==0){
            mp[s[j]]='A'+i;
            i++;
        }
    }
    for(int i=0;i<s.size();i++){
        s[i]=mp[s[i]];
    }
    cout<<s<<endl;
}
signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}