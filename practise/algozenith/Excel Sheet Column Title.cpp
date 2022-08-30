#include <bits/stdc++.h>
using namespace std;
#define int long long
 vector<char>mp;
void solve()
{   int n;cin>>n;
string s="";
    while(n){ 
        s+=(n-1)%26+'A';
        n=(n-1)/26;
    }
    reverse(s.begin(),s.end());
     cout<<s<<endl;
}

signed main()
{
    for(auto ch= 'A';ch<='Z';ch++)mp.push_back(ch);
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}