#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        char c;
        cin>>c;
        int flag=1;
        for(int i=0;i<n;i++){
            if(s[i]==c && i%2==0){
                cout<<"YES\n";
                flag=0;
                break;
            }
        }
        if(flag)cout<<"NO\n";
    }
}