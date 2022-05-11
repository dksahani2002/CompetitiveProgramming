#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
void sol(){
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
     
    for(int i=n-1;i>0;i-=2){ 
            if(v[i]<v[i-1]){
                swap(v[i],v[i-1]); 
            } 
    } 
    for(int i=0;i<n-1;i++){
        if(v[i]>v[i+1]){ 
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    return;
}

signed main(){
    int t;cin>>t;
    while(t--){
        sol();
    }
 return 0;  
}