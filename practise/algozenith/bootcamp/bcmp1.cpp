#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int j=0;
    for(int i=0;i<n;i++){
        if(v[i]<=0){
            swap(v[i],v[j]);
            j++;
        }
    }
    vector<bool>res(1000001,true);
    res[0]=0;
    j=0;
    while(v[j]<=0 && j<n){
        j++;
    }
    for(;j<n;j++){
        res[v[j]]=0;
    }
    for(auto i=1;i<res.size();i++){
        if(res[i]){
            cout<<i<<endl;
            return;
        }
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