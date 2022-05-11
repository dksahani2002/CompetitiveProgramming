#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol(){ 
        int n,m;cin>>n>>m;
        vector<string>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int sum=INT_MAX;
         for(int i=0;i<n;i++){
             for(int j=i+1;j<n;j++){
                 int temp=0;
                 for(int k=0;k<m;k++){
                     temp+=abs(v[i][k]-v[j][k]);
                 }
                 sum=min(sum,temp);
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