#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int cont=0;
        while(n>0){
            if(n>=5){
                cont++;
                n-=5;
            }else if(n>=3){
                cont++;
                n-=3;
            }else{
                cont+=n;
                n=0;
            }
        }
        cout<<cont<<endl;
    }
    return 0;
}