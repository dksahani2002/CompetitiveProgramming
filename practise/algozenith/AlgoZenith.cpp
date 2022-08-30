#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
     int n;
     cin>>n;
     for(int i=1;i<=n;i++){
         if(i%15==0 && i>=15){
             cout<<"AlgoZenith"<<endl;
         }else if(i%3==0 && i>=3){
             cout<<"Algo"<<endl;
         }else if(i%5==0 && i>=5){
             cout<<"Zenith"<<endl; 
         }else{
             cout<<i<<endl;
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