#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    int t;cin>>t;
    while(t--){
         string s;
         cin>>s;
         int n=s.size();
         if(n==1){
             cout<<1<<endl;
             continue;
         }
         int z=n-1,count1=0;
         for(int i=n-1;i>=0;i--){
             if(s[i]=='0'){
                 z=i;
             }
         } 
        int x=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                x=i;
            }
        }
        cout<<z-x +1<<endl;
    }
    return 0;
}