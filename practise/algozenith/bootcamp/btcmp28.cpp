#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
void solve()
{
    int n;cin>>n;
    vector<vector<int>>v(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>v[i][0]>>v[i][1];
    }
    sort(v.begin(),v.end(),cmp);
    int ans=1;
    int last=0;
    for(int i=1;i<n;i++){
        if(v[i][0]>v[last][1]){
            last=i;
            ans++;
        }
    }
    cout<<ans<<endl;
}

signed main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t=1;
    // cin >> _t;
    while (_t--)
        solve();
}