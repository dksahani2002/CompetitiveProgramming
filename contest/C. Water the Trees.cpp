#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int caldays(int height,int hi[]){
    int ones=0,twos=0,days=0;
        for(int i=0;i<n;i++){
            int diff=height-hi[i];
            ones+=diff%2;
            
            twos+=diff/2;
            
        }
        if(ones>twos){
            return 2*ones-1;
        }
        // cout<<"ones"<<ones<<" "<<"twos"<<twos<<endl;
        days=min(ones,twos);
        
        ones-=days;
        twos-=days;
        days*=2;
        // cout<<"days"<<days<<endl;
        // cout<<"ones"<<ones<<" "<<"twos"<<twos<<endl;
        if(twos==0){
            days+=ones;
        }else{
            if(twos/3>0){
                //  cout<<"twos"<<twos<<endl;
                 int mul=twos/3;
                 
                days+=4*mul;
                twos%=3;
            //    cout<<"twos"<<twos<<endl;
            }
            if(twos==2) {
                days+=3;
            }else{
                days+=2;
            }
            
        }
        return days;
}
signed main(){
    int t;cin>>t;
    while(t--){
        cin>>n;
        int hi[n];
        int height=0;
        for(int i=0;i<n;i++){
            cin>>hi[i];
            height=max(height,hi[i]);
        }
        int d1=caldays(height,hi);
        int d2 = caldays(height+1,hi);
        cout<<min(d1,d2)<<endl;
        
    }
}