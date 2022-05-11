#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol(){ 
        int n,m;cin>>n>>m;
        int v[n][m],up[n][m]={0},dn[n][m]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        int sum=INT_MIN;
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                   int temp=v[i][j];
                   int l=i-1;
                   int r=j-1;
                   while(l>=0 && r>=0){
                       temp+=v[l][r];
                       l--;
                       r--;
                   }
                   l=i-1;
                   r=j+1;
                   while(l>=0&&r<m){
                       temp+=v[l][r];
                       l--;r++;
                   }
                   l=i+1;
                   r=j-1;
                   while(l<n && r>=0){
                       temp+=v[l][r];
                       l++;r--;
                   }
                   l=i+1;
                   r=j+1;
                   while(l<n && r<m){
                       temp+=v[l][r];
                       l++;r++;
                   }
                   sum=max(sum,temp);
             }
        } 
        cout<<sum<<endl;
     return;
}
signed main(){
    int t;cin>>t;
    while(t--){
        sol();
    }
}