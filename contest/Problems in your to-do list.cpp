#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void sol()
{
    // string s;
    int n;cin>>n;

     vector<int>v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     sort(v.begin(),v.end());
     int ans=0;
     for(int i=0;i<n;i++){
         if(v[i]>=1000)ans++;
     }
     cout<<ans<<endl;
    return;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        sol();
}