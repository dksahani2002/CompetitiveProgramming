#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        map<char,int>mp;
        int n=s.size();
        int index=n;
        for(int i=0;i<s.size();i++){
              if(mp.find(s[i])!=mp.end()){
                  index=i;
                  break;
              }else{
                  mp[s[i]]++;
              }
        }
         int flag=1;
        for(int i=index;i<s.size();i++){
             if(s[i]!=s[i%index]){
                 flag=0;
                 break;
             }
        }
        if(flag){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    //     map<char,int>mp;
    //     int n=s.size(),i=1;
    //     string p = string(n,s[0]);
    //     if(p==s){
    //         cout<<"YES\n";
    //         continue;
    //     }
    //     mp[s[0]]++;
    //     int flag=1,flag2=1;
    //     while(i<n){
    //         mp[s[i]]++;
    //         if(s[i]==s[i-1]){
    //             cout<<"NO\n";
    //             flag=0;
    //             break;
    //         }
    //         if(mp[s[i]]>1){
    //             flag2=0;
    //         }
    //         i++; 
    //     }
    //     if(flag2){
    //         cout<<"YES\n";
    //         continue;
    //     }
    //     int k=mp.size();
    //     int l=0,r=0;
    //     map<char,int>mp2;
    //     for(int i=r;i<n;i++){
             
    //          if(mp2.size()==k){

    //          }
    //     }
        
    //    if(flag) cout<<"YES\n";
    }
    return 0;
}