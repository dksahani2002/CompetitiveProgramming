#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
    int n;cin>>n;
     vector<int>v(n),temp(n) ;
     for(int i=0;i<n;i++){
         cin>>v[i];
         temp[i]=v[i];
     }
     sort(temp.begin(),temp.end());
        int ans=(1<<20)-1;
     for(int i=n-1;i>=0;i--){
         if(v[i]!=temp[i]){
               ans&=temp[i];
             
         }
     } 
     cout<<ans <<endl;
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