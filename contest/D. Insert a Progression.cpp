#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int mx=*max_element(v.begin(),v.end());
        int mn=*min_element(v.begin(),v.end());
        int ans=0;
        for(int i=1;i<n;i++){
            ans+=abs(v[i]-v[i-1]);
           
        }
        if(1<mn){
            ans+=min({2*abs(mn-1),abs(v[0]-1) , abs(v[n-1]-1)});
            
        }
        if(x>mx){
            ans+=min({2*abs(mx-x),abs(v[0]-x) , abs(v[n-1]-x)});
              
        }
        cout<<ans<<endl;
    }
    return 0;
}