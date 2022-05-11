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
        int count=0;
        int flag=1;
        for(int i=n-2;i>=0;i--){
            if(v[i+1]==0){
                cout<<-1<<endl;
                flag=0;
                break;
            }
            while(v[i]>=v[i+1]){
                v[i]/=2;
                count++;
            }
        }
       if(flag)cout<<count<<endl;
    }
    return 0;
}