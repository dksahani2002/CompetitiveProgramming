#include <bits/stdc++.h>
using namespace std;
#define int long long
void rec(int i , int n, string &s, string temp ,vector<string>&ans ){
    if(i==n){
        ans.push_back(temp);
        return;
    }
    int op1=s[i]-'0';
   
    if(op1>=1 && op1<=9){
         temp+=op1+'A'-1;
        rec(i+1,n,s,temp,ans);
        temp.pop_back();
    }
    if(i<n-1){
        int op2=10*op1+s[i+1]-'0';
        if(op2<27 && op1>0){
            temp+=op2+'A'-1;
            rec(i+2,n,s,temp,ans);
            temp.pop_back();
        }
    }

}
void solve()
{ 
     string s;cin>>s;
     vector<string>v;
     string temp="";
     int n=s.size();
     rec(0,n,s,temp,v);
     for(auto i:v){
         cout<<i<<endl;
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