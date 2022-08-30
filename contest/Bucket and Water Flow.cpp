#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void sol()
{
    // string s;
     int w,x,y,z;
     cin>>w>>x>>y>>z;
     if((x-w)<y*z){
         cout<<"overFlow\n";
     }else if((x-w)==y*z){
         cout<<"filled\n";
     }else{
          cout<<"Unfilled\n";
     } 
    return;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        sol();
}