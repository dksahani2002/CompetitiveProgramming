#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    int t;cin>>t;
    while(t--){
        int a,b,c,x,y;
        cin>>a>>b>>c>>x>>y;
        int dog=0,cat=0;
        if(a>=x)dog=1;
        else {
            x-=a;
            if(c>=x)dog=1;
            c-=x;
        }
        if(b>=y)cat=1;
        else{
            y-=b;
            if(c>=y)cat=1;
        }
        if(cat==1 && dog==1){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}