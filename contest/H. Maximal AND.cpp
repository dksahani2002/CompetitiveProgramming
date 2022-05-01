#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        // int ma=-1e9;

        for(int i=0;i<n;i++){
            cin>>v[i];
            // ma=max(ma,v[i]);
        }
        int ans=0;
        // map<int,int>mp;
        for(int i=30;i>=0;i--){
            int count=0;
            for(int j=0;j<n;j++){
                if(v[j]&(1<<i)){
                    continue;
                }else{
                    count++;
                }
            }
            if(count<=k){
                k-=count;
                ans+=(1<<i);
            }
        } 
        cout<<ans<<endl;
    }
    return 0;
}