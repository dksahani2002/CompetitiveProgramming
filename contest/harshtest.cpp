#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>getNumPairs(vector<int> v, vector<int>query){
    int n=v.size();
    int m=query.size();
    vector<int>pfm(n),sfm(n);
    map<int,int>pf,sf;
    for(int i=0;i<v.size();i++){
        if(i)pfm[i]=max(pfm[i-1],v[i]);
        else pfm[i]=v[i];
        pf[pfm[i]]++;
    }
    map<long long,long long>mp;
    for(int i=n-1;i>=0;i--){
        if(i!=n-1)sfm[i]=min(sfm[i+1],v[i]);
        else sfm[i]=v[i];
        sf[sfm[i]]++;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         mp[pfm[i]*sfm[j]]++;
    //     }
    // }
    for(int i=1;i<=1e5;i++){
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                if(sf.find(j)!=sf.end() && pf.find(i/j)!=pf.end() ){
                    mp[i]+=sf[j]*pf[i/j];
                }
                if(sf.find(i/j)!=sf.end() && pf.find(j)!=pf.end() ){
                    mp[i]+=sf[i/j]*pf[j];
                } 
            }
        }
    }
    vector<int>res;
    for(int i=0;i<m;i++){
        res.push_back(mp[query[i]]);
    }
    return res;
}
void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int>v(n),query(q);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int j=0;j<q;j++)cin>>query[j];
    vector<int>ans=getNumPairs(v,query);
    for(auto i:ans){
        cout<<i<<" ";
    }
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