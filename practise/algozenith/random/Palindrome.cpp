#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
     string s,temp;
     cin>>s;
     int n=s.size();
     int l=0,r=s.length()-1;
     while(s[l]==s[r] && l<r){
         l++;
         r--;
     }
     if(l>=r){
         cout<<"Y\n";
         return;
     }else{
         temp="";
         temp+=s.substr(0,l);
         temp+=s.substr(l+1,n-l);

         string rev=temp;
         reverse(rev.begin(),rev.end()); 
         if(temp==rev){ 
             cout<<"Y\n";
             return;
         }
         
         temp="";
         temp+=s.substr(0,r);
         temp+=s.substr(r+1,n-r); 
         rev=temp;
         reverse(rev.begin(),rev.end()); 
         if(temp==rev){
             cout<<"Y\n";
             return;
         }
         cout<<"N\n";
     }
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
}