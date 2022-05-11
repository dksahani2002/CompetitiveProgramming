#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol(){
    int n;cin>>n;
    vector<int>v(n);
    map<int,int>mp;
    int count=0;
    int fq=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]!=0)count++;
        mp[v[i]]++;
        if(mp[v[i]]>1)fq=1;
    }
    if(count<n){
        cout<<count<<endl;
        return;
    }
    if(fq){
        cout<<n<<endl;
        return;
    }else{
        cout<<n+1<<endl;
        return;
    }
}
signed main(){
    int t;cin>>t;
    while(t--){
        sol();
    }
}