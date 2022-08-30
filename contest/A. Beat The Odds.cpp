#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
     int n;cin>>n;
     vector<int>v(n);
     int odd=0,even=0;
     for(int i=0;i<n;i++){
         cin>>v[i];
         if(v[i]&1){
             odd++;
         }else{
             even++;
         }
     }
     cout<<min(odd,even)<<endl;
    return;
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