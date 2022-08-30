#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,s;
    cin>>n>>s;
    vector<int>v(n);
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
        mp[v[i]]++;
    }
    sort(v.begin(),v.end());
    // for(int i=0;i<n-1;i++){
    //     if(mp.find(s-v[i])!=mp.end()){
    //         if(v[i]*2==s){
    //             if(mp[v[i]]>1){
    //                 cout<<"Y\n";
    //                 return;
    //             }
    //         }else{
    //             cout<<"Y\n";
    //             return;
    //         }
    //     }
    // }
    int l=0,r=n-1;
    while(l<r){
        if(v[l]+v[r]==s){
             cout<<"Y\n";
             return;
        }
        if(v[l]+v[r]<s){
            l++;
        }else r--;
    }
    cout<<"N\n";
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}