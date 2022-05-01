#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;cin>>n;
    int num[n];
    for(int i=0;i<n;i++){
        cin>>num[i];
       
    }
    for(int i=0;i<n;i++){
        if(num[i]==0){
            cout<<0<<" ";
            continue;
        }
        int ans=1e9; 
        for(int j=num[i];j<=num[i]+15;j++){
            int oper=j-num[i]; 
           ;
            int x=j;
            int powneed=0;
             while(x%2==0){
                 powneed++;
                //   cout<<oper<<" "
                 x/=2;
             }
             if(powneed<15)oper+=(15-powneed);
             ans=min(ans,oper);
        }
        cout<<ans<<" ";
    }
}