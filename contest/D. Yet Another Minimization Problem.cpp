#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int sum=0;
        for(int i=0;i<n;i++){
             for(int j=i+1;j<n;j++){
                 sum+=pow((a[i]+a[j]+b[i]+b[j]),2);
             }
        }
        int sum2=0;
        for(int i=0;i<n;i++){
             for(int j=i+1;j<n;j++){
                //  if((a[i]+b[j])*(b[i]+a[j])>(a[i]+a[j])*(b[i]+b[j])){
                //      sum2+=(a[i]+b[j])*(b[i]+a[j]);
                //      swap(a[j],b[j]);
                //  }else{
                //      sum2+=(a[i]+a[j])*(b[i]+b[j]);
                //  }
                sum2+=max((a[i]+a[j])*(b[i]+b[j]),(a[i]+b[j])*(b[i]+a[j]));
             }
        }
        int ans=sum-2*sum2;
        cout<<ans<<endl;
    }
}