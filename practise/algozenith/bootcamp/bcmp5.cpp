#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    string s;
    cin>>s;
    vector<vector<int>>v(26);
    for(auto i=0;i<s.size();i++)v[s[i]-'a'].push_back(i);
    int ans=1;
    for(auto x:v){
        int cur=1,pre=0,res=0;
        for(int i=1;i<x.size();i++){
            if(x[i]==x[i-1]+1)cur++;
            else if(x[i]==x[i-1]+2){
                pre=cur;
                cur=1;
            }else{
                pre=0;
                cur=1;
            }
            res=max(res,cur+pre);
        }
        ans=max(ans,res+(x.size()>(cur+pre)));
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