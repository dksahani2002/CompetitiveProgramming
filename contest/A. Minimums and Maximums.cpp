#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol(){
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    if(l1<=l2 && r1>=l2){
        cout<<max(l1,l2)<<endl;
    }else if(l2<=l1 && l1<=r2){
        cout<<max(l1,l2)<<endl;
    }else{
        cout<<l1+l2<<endl;
    }
    return;
}
signed main(){
    int t;cin>>t;
   while(t--) sol();
}