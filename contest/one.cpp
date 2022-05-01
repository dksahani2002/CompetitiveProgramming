#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
         vector<int>v,w;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            
             v.push_back(x);
        }
        for(int i=0;i<n;i++){
            cin>>x;
            
             w.push_back(x);
        }
        int ans=0;
        int c;
        for(auto i=1;i<v.size();i++){ 
              c=min(abs(v[i]-v[i-1])+abs(w[i]-w[i-1]) ,abs(v[i]-w[i-1])+abs(w[i]-v[i-1]));
              ans+=c;
        }
        // ans-=abs(v[n]-v[n-1]);
        cout<<ans<<endl;
    }
}