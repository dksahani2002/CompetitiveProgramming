#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
    string s,t;
    cin>>s>>t;
    // map<char,int>s1 ;
    // for(int i=0;i<s.length();i++){
    //     s1[s[i]]++;
    // }
    // for(int i=0;i<t.length();i++){
    //     s1[t[i]]--;
    // }
    // for(auto i:s1){
    //     if(i.second){
    //         cout<<"N\n";
    //         return;
    //     }
    // }
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(s==t)cout<<"Y\n";
    else cout<<"N\n";
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