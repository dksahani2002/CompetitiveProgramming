#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int k;
        cin>>k; 
        // map<char,int>mp;
        vector<int>v(26,-1);
        for(int i=0;i<k;i++){
            char c;
            cin>>c;
            v[c-'a']='1';
        } 
        int l=0,ans=0;
         for(int i=0;i<n;i++){
             if(v[s[i]-'a']!=-1){
                 ans=max(ans,i-l);
                 l=i;
             }
         }
        
        // ans=max(ans,r-l+1);
        cout<<ans<<endl;
    }
    return 0;
}