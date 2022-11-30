#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    string s;cin>>s;
    string ans="";
    ans+=s[0];
    for(int i=1;i<s.size();i++){
        int l=i-1;
        int r=i+1;
        if(s[i]==s[i-1]){
            l=i-2;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                l--;r++;
            }
            l++;
            r--;
            if(ans.size()<r-l+1){
                ans=s.substr(l,r-l+1);
            }
        }
        l=i-1;
        r=i+1;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;r++;
        }
        l++;
        r--;
        if(ans.size()<r-l+1){
            ans=s.substr(l,r-l+1);
        }
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