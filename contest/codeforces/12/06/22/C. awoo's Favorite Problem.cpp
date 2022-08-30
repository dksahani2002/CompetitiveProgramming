#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
     string s,t;
     cin>>s>>t; 
      if(s==t){
        cout<<"YES\n";
        return;
      }
      int k=0;
      for(int i=0;i<n-1;i++){
            if(k<=i){
                k=i;
            }
        if(s[i]!=t[i]) {
               if(s[i]=='a'){ 
                    while(k<n && s[k]!='b'){
                        if(s[k]=='c'){
                            cout<<"NO\n";
                            return;
                        } 
                        k++;
                    }
                    if(k==n){
                            cout<<"NO\n";
                            return;
                        }
                    s[k]='a';
                    s[i]='b';
               }else if(s[i]=='b'){
                     
                    while(k<n && s[k]!='c'){
                        if(s[k]=='a'){
                            cout<<"NO\n";
                            return;
                        }
                        k++;
                    }
                    if(k==n){
                            cout<<"NO\n";
                            return;
                    }
                    s[k]='b';
                    s[i]='c';
               }else{
                cout<<"NO\n";
                return;
               } 
        }
      }
      if(s==t){
        cout<<"YES\n" ;
      }else{
        cout<<"NO\n";
      }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}