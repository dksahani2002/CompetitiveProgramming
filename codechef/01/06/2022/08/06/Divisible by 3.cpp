 #include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int a,b;
    cin>>a>>b;
    if(a%3==0 || b%3==0){
        cout<<0<<endl;
    }else if(abs(a-b)%3==0){
        cout<<1<<endl;
    }else{
        cout<<2<<endl;
    }
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