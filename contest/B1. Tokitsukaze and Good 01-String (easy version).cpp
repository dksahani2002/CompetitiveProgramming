#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol(){
    int n;cin>>n;
     string s;cin>>s;
     int count=0;
     vector<int>v;
     int last=s[0];
     for(int i=0;i<s.size()-1;i+=2){
         if(s[i]==s[i+1]){
             last=s[i];
             break;
         } 
     }
     int segcount=0;
     for(int i=0;i<s.size()-1;i+=2){
         if(s[i]==s[i+1]){
             if(s[i]==last){

             }else{
                 segcount++;
             }
             last=s[i]; 
         }else{
             count++;
             s[i]=last;
             s[i+1]=last;
         } 
     }
     cout<<count<<" "<<segcount+1<<endl;
     return;
}
signed main(){
    int t;cin>>t;
    while(t--){
        sol();
    }
}