#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    string s="";
    for(int i=63;i>=0;i--){
        if(n&(1LL<<i))s.push_back('1');
        else s.push_back('0');
    }
    cout<<s<<endl;
    int i=0;
    while(i<s.size() && s[i]=='0')i++;
    cout<<63-i<<endl;
    i=s.size()-1;
    while(i>=0 && s[i]=='0')i--;
    cout<<((63-i)<=63?(63-i):-1)<<endl;
    if(n&(n-1)==0){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }
}
signed main()
{
    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}