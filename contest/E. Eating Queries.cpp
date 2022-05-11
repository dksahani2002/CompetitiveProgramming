#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol(){ 
        int n,q;cin>>n>>q;
        vector<int>v(n);
        map<int,int>pf;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            sum+=v[i];
        }
        sort(v.rbegin(),v.rend());  
        pf[0]=v[n-1];
        for(int i=1;i<n;i++){
            v[i]+=v[i-1]; 
        }
        while(q--){
            int s;cin>>s;
            int it=lower_bound(v.begin(),v.end(),s)-v.begin();
            if(it==n){
                cout<<-1<<endl;
            }else{
                cout<<it+1<<endl;
            }
        }
     return;
}
signed main(){
    int t;cin>>t;
    while(t--){
        sol();
    }
}