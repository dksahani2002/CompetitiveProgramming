#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    // getline();
    // char s[40];
    string ss;
    getline(cin,ss);
    char s[]=ss;
    vector<string>v;
    char *ptr=strtok(s," ");
    // cout<<ptr<<endl;
    while(ptr!=NULL){
        v.push_back(ptr);
        ptr=strtok(NULL," ");
    }
    for(auto x:v){
        cout<<x<<endl;
    }
}
signed main()
{
    fast;
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}