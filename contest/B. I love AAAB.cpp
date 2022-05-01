#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        if(n<3){
            if(s=="AB"){
                cout<<"YES\n";
                continue;
            }
            cout<<"NO\n";
            continue;
        }
        if(s[0]=='B'){
            cout<<"NO\n";
            continue;
        }else{
            if(s[n-1]!='B'){
                cout<<"NO\n";
                continue;
            }else{
                int countb=0,counta=0,flag=1;
                for(int i=0;i<n;i++){
                    if(s[i]=='B'){ 
                        countb++;
                        if(countb>counta){
                            cout<<"NO\n";
                            flag=0;
                            break;
                        }
                    }else{
                        counta++;
                    }
                }
                if(flag){
                    cout<<"YES\n";

                }
            }
        }
    }
    return 0;
}