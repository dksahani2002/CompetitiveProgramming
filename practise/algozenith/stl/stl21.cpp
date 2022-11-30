#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<int>v;
int ans;
void merge(int l, int mid, int r){
    vector<int>temp;
    int i=l;
    int j=mid+1;
    while(i<=mid && j<=r){
        int val=v[i]+v[j];
        if((val&(val-1))==0)ans++;
        if(v[i]<v[j]){
            temp.push_back(v[i]);
            i++;
        }else{
            temp.push_back(v[j]);
            j++;
        }
    }
    while(i<=mid){
        // int val=v[i]+v[mid+1];
        // if((val&(val-1))==0)ans++;
        temp.push_back(v[i++]);
    }
    while(j<=r){ 
        // int val=v[mid]+v[j];
        // if((val&(val-1))==0)ans++;   
        temp.push_back(v[j++]);
    }
    int k=l;
    for(auto x:temp){
        v[k]=x;
        k++;
    }

}
void mergesort(int l,int r){
    if(l>=r)return;
    int mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    merge(l,mid,r);
}
void solve()
{
    int n;cin>>n;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
     ans=0;
    // mergesort(0,n-1);
    // for(auto x:v){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    map<int,int>mp;
    int vv[33],mul=1;
    for(int i=0;i<=31;i++){
        vv[i]=mul;
        mul*=2;
    }
    for(int i=0;i<=31;i++){
        mp.clear();
        for(int j=0;j<n;j++){
            if(mp.count(vv[i]-v[j]))ans+=mp[vv[i]-v[j]];
            mp[v[j]]++;
        }
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