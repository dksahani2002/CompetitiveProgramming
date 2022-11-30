#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    string s,t;cin>>s>>t;
    map<char,int>mp1,mp2;
    for(auto x:t)mp1[x]++;
    int i=0;
    int ans=1e9;
    string res;
    int req=mp1.size();
    int cur=0;
    for(int j=0;j<s.size();j++){
         
        mp2[s[j]]++;
        while(i<=j && mp2.size()>mp1.size() ){
            if(mp2.count(s[i])){
                mp2[s[i]]--;
                if(mp2.count(s[i])==0)mp2.erase(s[i]);
            }
            i++;
        }
        if(req==mp2.size()){
            if(ans>(j-i+1)){
                ans=j-i+1;
                res=s.substr(i,j-i+1);
            }
        }
         
        
    }
    cout<<ans<<endl;
    cout<<res<<endl;
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