#include <bits/stdc++.h>
using namespace std;
#define int long long

// int rec(int i, int pi,vector<pair<int,int>>&v){
//     if(i>=v.size()){
//         return 0;
//     }
//     //taken 
//     int ans=-1e18;
//     if(pi==-1 || (v[pi].first>v[i].first && v[pi].second>v[i].second) ){
//         ans=1+rec(i+1,i,v);
//     }
//     // not taken;
//     ans=max(ans,rec(i+1,pi,v));
//     return ans;
// }
bool cmp(pair<int,int>p1,pair<int,int>p2){
    if(p1.first==p2.first)return p1.second>p2.second;
    return p1.first<p2.first;
}
void solve()
{
    int n;
    cin>>n;
    
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++)cin>>v[i].first;
    for(int i=0;i<n;i++)cin>>v[i].second;
    sort(v.begin(),v.end(),cmp);
    // int ans=rec(0,-1,v);
    vector<int>tmp;
    for(int i=0;i<n;i++){
        if(tmp.empty() || tmp.back()<v[i].second){
            tmp.push_back(v[i].second);
        }else{
            auto it=lower_bound(tmp.begin(),tmp.end(),v[i].second);
            *it=v[i].second;
        }
    }

    cout<<tmp.size()<<endl;
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