#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,r,c,x,y;cin>>n>>r>>c>>x>>y;
    string s;cin>>s;
    // map<char,pair<int,int>>mp;
    // mp['E']={1,0};
    // mp['W']={-1,0};
    // mp['N']={0,1};
    // mp['S']={0,-1};
    set<pair<int,int>>st;
    for(int i=0;i<s.size();i++){
        int nx=x+mp[s[i]].first;
        int ny=y+mp[s[i]].second;
        if(st.count({nx,ny})==0 && nx<=r && ny<=c){
            x=nx;
            y=ny;
            st.insert({x,y});
        }
    }
    cout<<x<<" "<<y<<endl;

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