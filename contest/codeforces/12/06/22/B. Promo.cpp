#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int>v(n+1);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>v[i];  
    }
     sort(v.rbegin(),v.rend());
      
     for(int i=1;i<n;i++){
       v[i]+=v[i-1];
        
     }
     while(q--){
        int x,y;
        cin>>x>>y;
         if(x==y){
            cout<<v[x-1]<<endl;
             
         }else{
            cout<<v[x-1]-v[x-y-1]<<endl;
         }
        
     }
     
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