#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
     int n,k;
     cin>>n>>k;
     if(k==1){
         if(n&1){
             cout<<"ODD\n";
         }else{
             cout<<"EVEN\n";
         }
     }else if(k==2){
          cout<<"ODD\n";
     }else{
         cout<<"EVEN\n";
     }
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