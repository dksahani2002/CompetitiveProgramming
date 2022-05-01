#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        if(n==1){
            cout<<"YES\n";
            continue;
        }
        if(n==2 ){
            if((v[1]-v[0]) <=3){
                cout<<"YES\n";
                continue;
            }else{
                cout<<"NO\n";
                continue;
            } 
        }
        int flag=1;
        v[0]++;
        for(int i=1;i<n;i++){
            if(v[i]-v[i-1] >=3){
                cout<<"NO\n";
                flag=0;
               break;
            }else if(v[i]-v[i-1]==2){
                 v[i]--;
            }if(v[i]-v[i-1]==0){
                v[i]++;
            }
        }
      if(flag)cout<<"YES\n";
        
    }
}