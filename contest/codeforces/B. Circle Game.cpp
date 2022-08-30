#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    int g[n];
    int idx=0;
    for(int i=0;i<n;i++){
         cin>>g[i]; 
         
         if(g[i]<g[idx]){
            idx=i;
         }
    }
    if(n&1){
        cout<<"Mike\n";
        return;
    } 
    if((idx)&1){
        cout<<"Mike\n";
    }else{
        cout<<"Joe\n";
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