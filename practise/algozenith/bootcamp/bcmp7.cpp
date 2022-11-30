#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<vector<int>>v(n,vector<int>(2));
    for(int i=0;i<n;i++)cin>>v[i][0]>>v[i][1];
    sort(v.begin(),v.end());
    int l=v[0][0],r=v[0][1];
    vector<vector<int>>ans;
    for(auto e:v){
        if(e[0]>r){
            ans.push_back({l,r});
            l=e[0];
            r=e[1];
        }else{
            l=min(l,e[0]);
            r=max(r,e[1]);
        }
    }
    ans.push_back({l,r});
    for(auto e:ans){
        cout<<e[0]<<" "<<e[1]<<endl;
    }

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