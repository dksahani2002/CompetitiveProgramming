#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    string s;
    getline(cin,s);
    int n=s.length();
    n--;
    int l=0,r=n;
    // cout<<s<<endl;
    while(l<r){
        if(s[l]==' ' || s[l]<'a' || s[l]>'z'){
            l++;continue;
        }
        if(s[r]==' ' || s[r]<'a' || s[r]>'z'){
            r--;continue;
        }
        if(s[l]!=s[r]){
            cout<<"NO\n";
            return;
        }
        l++;
        r--;
    }
    cout<<"YES\n";
}
signed main()
{
    int t=1;
    cin >> t;
    string temp;
    getline(cin,temp);
    while (t--)
    {
        solve();
    }
}