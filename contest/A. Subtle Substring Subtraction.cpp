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
            int x= s[0]-'a';
            cout<<"Bob "<<x+1<<endl;
            continue;
        }else if(n%2==0){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+= s[i]-'a'+1;
                 
            }
            cout<<"Alice "<<sum<<endl;
        }else{
             int sum1=0,sum2=0;
            for(int i=0;i<n;i++){
                if(i!=0)sum1+= s[i]-'a'+1 ;
                if(i!=n-1)sum2+= s[i]-'a'+1 ;
                
            }
            sum1-=s[0]-'a'+1;
            sum2-=s[n-1]-'a'+1;
            cout<<"Alice "<<max(sum1 , sum2)<<endl;
        }
    }
}