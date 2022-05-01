#include <bits/stdc++.h>
using namespace std;
#define int long long  
  signed main(){
          int t;cin>>t;
          int n,m,k;
          cin>>n>>m>>k;
          int xi[n];
          for(int i=0;i<n;i++){
              cin>>xi[i];
          }
          vector<vector<pair<int,int>>>g;
          vector<int>row;
            int a,b,c,d,hi;
            int node=1;
         int arr[n+1][m+1]={0};
           int nod=2,count=0,cur_row=0;
          for(int i=0;i<k;i++){
              cin>>a>>b>>c>>d>>hi; 
              if(a==1 && count==0){
                  g[1].push_back({2,abs(d-b)*xi[a-1]});
                  count++;
              } 
              if(cur_row==a ){
                  g[nod].push_back({node,abs(d-b)*xi[a-1]});
              }
              cur_row=a;
               g[nod].push_back({nod+1,-hi}); 
          }
         
  }