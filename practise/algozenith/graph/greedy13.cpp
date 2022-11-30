#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<int>fb;
void onit(){
    fb.resize(45);
    fb[1]=1;
    fb[2]=1;
    for(int i=3;i<45;i++){
        fb[i]=fb[i-1]+fb[i-2];
    }
}
// map<pair<int,int>,int>mp;
// int rec(int i, int left){
//     if(i>=45){
//         if(left==0)return 0;
//         return 1e9;
//     }
//     if(left<0)return 1e9;
//     if(mp.find({i,left})!=mp.end())return mp[{i,left}];
//     return mp[{i,left}]= min(1+rec(i,left-fb[i]),rec(i+1,left));
// }
void solve()
{
    int k;cin>>k;
    // cout<<fb[100]<<endl;
    // cout<<rec(1,k)<<endl;
    int ans=0;
    while(k){
        auto it=upper_bound(fb.begin(),fb.end(),k);
        it--;
        k-=*it;
        ans++;
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;
    onit();
    cin >> t;
    while (t--)
    {
        solve();
    }
}