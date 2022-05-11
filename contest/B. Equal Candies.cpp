#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol(){ 
        int n;cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i]-v[0];
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