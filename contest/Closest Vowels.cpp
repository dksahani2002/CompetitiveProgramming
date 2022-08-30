#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
void solve()
{ 
    int n;cin>>n;
    string s;
    cin>>s; 
    int ans=1;
    for(int i=0;i<s.size();i++ ){
        char ch=s[i];
        if(ch=='c' || ch=='g' || ch=='l' || ch=='r'){
            ans=ans*2%mod;
        }
    }
    cout<<ans<<endl;
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