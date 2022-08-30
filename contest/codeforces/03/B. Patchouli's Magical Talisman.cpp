#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    int odd=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]&1)odd++;
    }
    if(odd){
        cout<<n-odd<<endl;
    }else{
        cout<<n+1<<endl;
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