#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    string s;cin>>s;
    vector<int>v(26,-1),g(26,-1);
    for(int i=0;i<s.size();i++)v[s[i]-'a']=i;
    for(int i=s.size()-1;i>=0;i--)g[s[i]-'a']=i;
    vector<vector<int>>res;
    for(int i=0;i<26;i++){
        if(v[i]==-1 && g[i]==-1)continue;
        res.push_back({g[i],v[i]});
    }
    sort(res.begin(),res.end());
    int l=res[0][0],r=res[0][1];
    int i=1;
    while(l==r && i<res.size()){
        cout<<1<<" ";
        l=res[i][0];
        r=res[i][1];
        i++;
    }
    for(;i<res.size();i++){
        if(res[i][0]>=r){
            cout<<r-l+1<<" ";
            l=res[i][0];
            r=res[i][1];
        }else{
            l=min(l,res[i][0]);
            r=max(r,res[i][1]);
        }
    }
    cout<<r-l+1<<endl;
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