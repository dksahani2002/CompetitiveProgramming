#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
 
void solve()
{
     string s;
     cin>>s;
     int l=0,r=s.size()-1;
     int del=0;
     while(l<r){
        if(s[l]==s[r]){
            l++;r--;
        }else{
            break;
        }
     }
     string t=s.substr(0,r)+s.substr(r+1);
     string revt=t;
     reverse(revt.begin(),revt.end());
     if(t==revt){
     cout<<"Y\n";
        return;
     }
       t=s.substr(0,l)+s.substr(l+1);
       revt=t;
     reverse(revt.begin(),revt.end());
      if(t==revt){
     cout<<"Y\n";
        return;
     }
     cout<<"N\n";
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