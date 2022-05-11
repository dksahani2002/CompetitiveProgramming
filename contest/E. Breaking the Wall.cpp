#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    int n;
    cin>>n;
    vector<int>v(n),sot(n);
    int ans1=0,ans2=INT_MAX,ans3=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sot[i]=v[i];
    }
    //case1
    sort(sot.begin(),sot.end());
    ans1=(sot[0]+1)/2+(sot[1]+1)/2;
    // case2
    for(int i=0;i<n;i++){
        int val=INT_MAX;
        if(i+2<n){
            val=v[i]/2+v[i+2]/2;
            if(v[i]&1 or v[i+2]&1)val+=1;
        }
         ans2=min(ans2,val);
    }
    //case3
    for(int i=0;i<n-1;i++){
        if(v[i]>v[i+1]){
            if(v[i]>=2*v[i+1]){
                ans3=min(ans3,(v[i]+1)/2);
            }else{
                ans3=min(ans3,(v[i]+v[i+1]+2)/3);
            }
        }else{
            if(2*v[i]<=v[i+1]){
                ans3=min(ans3,(v[i+1]+1)/2);
            }else{
                ans3=min(ans3,(v[i]+v[i+1]+2)/3);
            }
        }
    }
    int ans=min(ans2,ans1);
    ans=min(ans,ans3);
    cout<<ans<<endl;
}