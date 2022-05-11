#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+3;j<n;j++){
            for(int k=i+1;k<j-1;k++){
                for(int l=k+1;l<j;l++){
                        if(v[i]<v[l] && v[j]<v[k])count++;
                } 
            }
        }
    }
     
    cout<<count<<endl;
     return;
}
signed main(){
    int t;cin>>t;
    while(t--){
        sol();
    }
}