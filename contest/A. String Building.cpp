#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        if(n==1){
            cout<<"NO\n";
            continue;
        } 
        if(n==2){
            if(s=='aa' || s=='bb'){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
            continue;
        }
        int flag=1;
        for(int i=0;i<n;i++){
            if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='a' && i+2<n){
                cout<<"NO\n";
                flag=0;
                break;
            }
             if(s[i]=='b' && s[i+1]=='a' && s[i+2]=='b' && i+2<n){
                cout<<"NO\n";
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<"YES\n";
        }
    }
}