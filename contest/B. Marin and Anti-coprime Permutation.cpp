#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n ;
        cin>>n;
        if(n&1){
            cout<<0<<endl;
        }else{
            int ans=1;
            for(int i=1;i<=n/2;i++){
                ans=(ans*i)%998244353;
            }
            ans=(ans*ans)%998244353;
            cout<<ans<<endl;
        }
    }
}