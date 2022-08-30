#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
     int n,m;cin>>n>>m;
     int v[n][m];
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++)cin>>v[i][j];
     }
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++)cin>>v[i][j];
     } 
     int  i=0,x=0,y=0;
     while(x<n && y<m){ 
         for(i=y;i<m;i++){
             cout<<v[x][i]<<" ";
         }
         x++;
         for(i=x;i<n;i++){
             cout<<v[i][m-1]<<" ";
         }
         m--;
         if(x<n){
             for(i=m-1;i>=y;i--){
                 cout<<v[n-1][i]<<" ";
             }
             n--;
         }
         if(y<m){
             for(i=n-1;i>=x;i--){
                 cout<<v[i][y]<<" ";
             }
             y++;
         }
        //   while(j<m-1-i && it<(m+n)){
        //       cout<<v[i][j]<<" ";
        //       j++;
        //       it++;
        //   }
        //   int t=i;
        //   while(i<n-t-1 && it<(m+n)){
        //       cout<<v[i][j]<<" ";
        //       i++;
        //       it++;
        //   }
        //   int x=j;
        //   while(j>(m-x-2) && it<(m+n)){
        //       cout<<v[i][j]<<" ";
        //       j--;
        //       it++;
        //   }
          
        //   while(   it<(m+n)){
        //       cout<<v[i][0]<<" ";
        //       i--;
        //       it++; 
        //   }
          
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