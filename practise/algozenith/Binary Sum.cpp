#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string s,t;
    cin>>s;
    cin>>t;  
    vector<int>v;
    int cary=0;
    int i=s.length()-1;
    int j=t.length()-1;
    while(i>=0 || j>=0 || cary){
        if(i>=0){
            cary+=s[i]-'0';
            i--;
        }
        if(j>=0){
            cary+=t[j]-'0';
            j--;
        }
        v.push_back(cary%2);
        cary/=2;
    }
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i];
    }        
}

signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}