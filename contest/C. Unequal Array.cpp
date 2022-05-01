#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int match=v[0],count=1,ans=0,flag=1;

        for(int i=1;i<n;i++){
            if(match==v[i]){
                count++; 
            }else{
                if(count>1){
                     mp[count]++; 
                }
                match=v[i];
                count=1;
            }
        }
         mp[count]++;
         for(auto i:mp){
             if(i.first==1)continue;
             else if(i.first==2  ){
                 if(i.second==1){
                     continue;
                 }
                 ans+=(i.first/2)*(i.second);
             }else{
                 ans+=(i.first/2)*(i.second);
             }
         }
        cout<<ans<<endl;
    }
}