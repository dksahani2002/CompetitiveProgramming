#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
     int n;cin>>n;
     vector<int>v(n);
     map<int,int>mp;
     for(int i=0;i<n;i++){
         cin>>v[i];
         mp[v[i]]++;
     } 
     int j=0;
     for(int i=0;i<n;i++){
         if(v[i]>0){
             swap(v[i],v[j++]);
         }
     }
      n=j;
      int i;
     for( i=0;i<n;i++){
         if(abs(v[i])-1<n && v[abs(v[i])-1]>0 )
            v[abs(v[i])-1]=-v[abs(v[i])-1];
     }
     for(i=0;i<n;i++){
         if(v[i]>0){
             cout<<i+1<<endl;
             return;
         }
     }
     cout<<i+1<<endl;
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