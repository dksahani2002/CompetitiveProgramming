#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol(){ 
       string s;
       cin>>s;
       int sum1=0,sum2=0;
       for(int i=0;i<s.size();i++){
           if(i<3){
               sum1+=s[i]-'0';
           }else{
               sum2+=s[i]-'0';
           }
       }
       if(sum1==sum2 ){
           cout<<"YES\n";
       }else{
           cout<<"NO\n";
       }
     return;
}
signed main(){
    int t;cin>>t;
    while(t--){
        sol();
    }
}