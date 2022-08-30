#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    char x=0;
    cout<<"x: "<<x<<endl;
    for(int i=0;i<2*n+1;i++){
        string s;cin>>s;
        for(auto ch:s)x^=ch;
    }
     
        cout<<x<<endl;
     

}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}