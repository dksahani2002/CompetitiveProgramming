#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
     int n,k;cin>>n>>k;
     string s;cin>>s;
       for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                 if(k>=(n-i-1)){
                     swap(s[n-1],s[i]);
                     k-=(n-i-1);
                     break;
                 }
         }
       }
        for(int i=0;i<n-1;i++){
        if(s[i]=='1'){
                if(k>=i){
                    swap(s[0],s[i]);
                    k-=i;
                    break;
                }
        }  
        }
      int sum=0;
      for(int i=0;i<n-1;i++){
          if(s[i]=='1' && s[i+1]=='1'){
              sum+=11;
          }
          if(s[i]=='1' && s[i+1]=='0'){
              sum+=10;
          }
          if(s[i]=='0' && s[i+1]=='1'){
              sum+=1;
          }
      }
      cout<<sum<<endl;
    return;
}

signed main()
{
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}