#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
     int n,m;
     cin>>n>>m;
     vector<int>v1(n),v2(m),ans;
     for(int i=0;i<n;i++)cin>>v1[i];
     for(int i=0;i<m;i++)cin>>v2[i];
     int l=0,r=0;
     if(n==0 || m==0){
         for(auto i:v1)cout<<i<<" ";
         for(auto i:v2)cout<<i<<" ";
         cout<<endl;
         return;
     }
     while(l<n || r<m){ 
         if(l<n){
             if(v1[l]>v2[r] && r<m){ 
                 ans.push_back(v2[r]);
                 r++;
             }else{
                 ans.push_back(v1[l]);
                 l++;
             }
         }
         if(r<m){ 
             if(v1[l]<v2[r] && l<n){
                //  cout<<"yaha aa rha"<<endl;
                 ans.push_back(v1[l]);
                 l++;
             }else{
                //  cout<<"yaha ni aa rha"<<endl;

                 ans.push_back(v2[r]);
                 r++;
             }
         }
     }
     for(auto i:ans)cout<<i<<" ";
     cout<<endl;
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