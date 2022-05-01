#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int time1=0,time2=0;
         time1=3*c/2;
          if(c&1){
              time1+=3;
          }
         time2=3*c/2;
         if(b&1){
            time2+=2*b/2+2;
            time1+=2*b/2;
        }else{
            time2+=2*b/2;
            time1+=2*b/2;
        } 
         if(time1>=time2){
             int diff=time1-time2;
             if(a>=diff){
                 a-=diff;
                 time2=time1;
             }else{
                 cout<<diff-a<<endl;
                 continue;
             }
             if(a&1){
                 cout<<1<<endl;
             }else{
                 cout<<0<<endl;
             }


         }else{
             int diff=time2-time1;
             if(a>=diff){
                 a-=diff;
                 time1=time2;
             }else{
                 cout<<diff-a<<endl;
                 continue;
             }
             if(a&1){
                 cout<<1<<endl;
             }else{
                 cout<<0<<endl;
             }
         }
         
         
        // cout<<abs(time1-time2)<<endl;
    }
    return 0;
}