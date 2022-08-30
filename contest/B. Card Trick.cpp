#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
     int n;cin>>n;
     vector<int>v(n);
     for(int i=0;i<n;i++)cin>>v[i];
     int m;cin>>m;
     vector<int>v2(m);
     for(int i=0;i<m;i++)cin>>v2[i];
     int top=0;
     for(int i=0;i<m;i++){
         int move=v2[i];
         if(top+move<n){
             top+=move;
         }else{
              
             top=(top+move)%n;
         }
     } 
     cout<<v[top]<<endl;
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