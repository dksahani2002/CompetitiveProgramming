#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int b,d2,bn;
int c,d3,cn;
bool iszero(){
    if(c<b)return 1;
    int lastb=(b+(bn-1)*d2);
    int lastc=(c+(cn-1)*d3);
    if(lastc>lastb)return 1;
    if(d3%d2>0)return 1;
    if(d3<d2)return 1;
    if((c-b)%d2>0)return 1;
    return 0;
}
bool isinf(){
    if(c-d3<b)return 1;
     int lastb=(b+(bn-1)*d2);
    int lastc=(c+(cn-1)*d3);
    if(lastc+d3>lastb)return 1;
    return 0;
}
void solve(){ 
    cin>>b>>d2>>bn; 
    cin>>c>>d3>>cn;
    if(iszero()){
        cout<<"0"<<endl;
        return;
    }
    if(isinf()){
        cout<<"-1"<<endl;
        return;
    }
    vector<int>v;
    for(int i=1;i<=sqrt(d3);i++){
        if(d3%i==0){
            if(d3/i==i)v.push_back(i);
            else {
                v.push_back(i);
                v.push_back(d3/i);
            }
            
        }
    }
    int ans=0;
    for(auto i:v){
        int d1=i;
        if(__gcd(d1,d2)*d3==d1*d2){
            ans=(ans+(d3/d1)*(d3/d1))%mod;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}