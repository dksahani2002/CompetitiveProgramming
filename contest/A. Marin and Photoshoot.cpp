#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0' &&s[i+1]=='0' &&(i+1)<n){
                ans+=2;
            }else{ 
                if(s[i-1]=='0'&& s[i+1]=='0' && (i-1)>=0 && (i+1)<n){
                    ans+=1;
                }
            }
            
        }
        cout<<ans<<endl;
    }
}