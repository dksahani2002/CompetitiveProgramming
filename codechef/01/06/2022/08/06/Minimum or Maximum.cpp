#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int i=0;
    int maxi=v[0];
    int mini=v[0];
    while(i<n){
        if(v[i]<maxi && v[i]>mini){
            cout<<"NO\n";
            return;
        }
        if(v[i]>maxi){
            maxi=v[i];
        }
        if(v[i]<mini){
            mini=v[i];
        }
        i++;
    }
    if(i==n){
        cout<<"YES\n";
        return;
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