#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
    int  n;cin>>n;
    int i;
    vector<int>v(n);
    for(  i=0;i<n;i++){
        cin>>v[i];
    } 
    sort(v.begin(),v.end());
    for( i=0;i<n;i++){
        if(v[i]==v[i+1]){
            cout<<v[i]<<endl;
            return;
        }
    }  
    return;
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