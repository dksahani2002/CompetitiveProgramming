#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int rec(string s){
    if(s.size()==1)return 1;
    int ans=0;
    for(int i=0;i<s.size();i++){
        int l=i;
        int r=i;
        while(l>=0 && s[l]==s[i])l--;
        while(r<s.size() && s[r]==s[i])r++;
        ans=max(ans,((r-l-1)*(r-l-1))+rec(s.substr(0,l+1)+s.substr(r)));
    }
    return ans;
}
void solve()
{
    int n;cin>>n;
    string s;
    cin>>s;
    cout<<rec(s)<<endl;
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