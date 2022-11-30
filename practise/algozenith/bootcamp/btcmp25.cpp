#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    string ans="";
    while(n){
        int temp=n%62;
        if(temp<26){
           ans+=temp+'a'; 
        }else if(temp<52){
            temp-=26;
            ans+=temp+'A';
        }else{
            temp-=52;
            ans+=temp+'0';
        }
        n/=62;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}

signed main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;
    cin >> _t;
    while (_t--)
        solve();
}